clf; % clears plot

M1 = [0 0]; % Motor 1 position
M2 = M1 + [30 -20]; % Motor 2, relativ to Motor 1
t1 = 0; 
t2 = 0;
% a vinkelrät med b om: t1=-24, t2=0 

M1t = 1.5;  % Motor torque [Nm]
M2t = 1.5;  %

% Phalanx and leaver-lengs in mm
a = 20; % mm
b = 90;
c = 60;
d = 50;
e = 50;
% a = 20;
% b = 70;
% c = 50;
% d = 30;
% e = 30;

h = animatedline;
Px = [0 0 t1 t2 a b c d e];


Q = fingerCalc(M1, M2, [0 0 t1 t2 a b c d e]);
        A = [Q(1) Q(2)];
        B = [Q(3) Q(4)];
        C = [Q(5) Q(6)];
        E = [Q(7) Q(8)];
        
% test equations
tt1 = deg2rad(t1);  % experemental deg, coonvertion is don otherwise in the function
tt2 = deg2rad(t2);

g = sqrt((M2(1)+a*cos(tt2)+M1(1)+c*sin(tt1))^2+(M2(2)+a*sin(tt2)+M1(2)-c*cos(tt1))^2);
g_t = norm(A-C);
g_t2 = norm(C-A);

Beta = acos((d^2+b^2-g^2)/(2*d*b));

AM1 = sqrt((M2(1)+a*cos(tt2)-M1(1))^2+(M2(2)+a*sin(tt2)-M1(2))^2);
AM1_t = norm(A-M1);

CM2 = sqrt((M2(1)-M1(1)+c*sin(tt1))^2+(M2(2)-M1(2)-c*cos(tt1))^2);
CM2_t = norm(C-M2); 

thetaL = acos((c^2+g^2-AM1^2)/(2*c*g));
alfaL = acos((g^2+a^2-CM2^2)/(2*g*a));
thetaV = acos((g^2+d^2-b^2)/(2*g*d));
alfaV = acos((b^2+g^2-d^2)/(2*b*g));

theta = thetaL + thetaV;
alfa = alfaL + alfaV;

B_ab = [M2(1)+a*cos(tt2)+b*cos(pi-alfa+tt2) M2(2)+a*sin(tt2)+b*sin(pi-alfa+tt2)];
B_cd = [M1(1)-c*sin(tt1)+d*sin(pi-theta-tt1) M1(2)+c*cos(tt1)+d*cos(pi-theta-tt1)];

E_ce = [M1(1)-c*sin(tt1)+e*sin((pi/2)-theta-tt1) M1(2)+c*cos(tt1)+e*cos((pi/2)-theta-tt1)];

%

hold on
plot([M2(1) A(1)],[M2(2) A(2)]) % a
plot([A(1) B(1)],[A(2) B(2)]) % b
plot([M1(1) C(1)],[M1(2) C(2)]) % c
plot([C(1) B(1)],[C(2) B(2)]) % d
plot([C(1) E(1)], [C(2) E(2)]) % e
%xlim([-100 100])
%ylim([-100 100])
xlim([-50 100])
ylim([-50 100])
% xlim([20 60])
% ylim([-30 10])

if abs(norm(A-M2)-a) > 0.1 || abs(norm(B-A)-b) > 0.1 || abs(norm(C)-c) > 0.1 || abs(norm(B-C)-d) > 0.1
    error('粪便');
end

% Force arows
ar = 10; % Arrow scalar

faxy = [cos(deg2rad(90)+tt2)*ar, sin(deg2rad(90)+tt2)*ar]; % fax fay, force vector from motor 2 and lever a
%fa = [faxy(2)*-cos(alfa-tt2) faxy(2)*sin(alfa-tt2)];
fa = [ar*sin(pi-alfa)*-cos(alfa-tt2) ar*sin(pi-alfa)*sin(alfa-tt2)]; % ar*sin(pi-alfa) = magnituden av kraften
fc = [ar*cos(deg2rad(180)+tt1), ar*sin(deg2rad(180)+tt1)];    % fcx fcy



%quiver(A(1),A(2),ar*cos(deg2rad(90)+tt2),0)     % A x
%quiver(A(1),A(2),0,ar*sin(deg2rad(90)+tt2))     % A y

quiver(A(1),A(2),faxy(1),0,'r')     % A x
quiver(A(1),A(2),0,faxy(2),'r')     % A y
quiver(A(1),A(2),faxy(1),faxy(2),'g')     % A xy
%quiver(A(1),A(2),ar*cos(alfa-pi-tt2),ar*-sin(alfa-pi-tt2),'b');
%quiver(A(1),A(2),ar*-cos(alfa-tt2),ar*sin(alfa-tt2),'b');
quiver(A(1),A(2),fa(1),fa(2),'b')   % A 

% quiver(B_cd(1),B_cd(2),ar*-sin(Beta),0,'r')    % B x
% quiver(B_cd(1),B_cd(2),0,ar*-cos(Beta),'r')    % B y
quiver(B_cd(1),B_cd(2),fa(1),0,'r')    % B x
quiver(B_cd(1),B_cd(2),0,fa(2),'r')    % B y
quiver(B_cd(1),B_cd(2),fa(2)*cos(-tt1-theta),fa(2)*sin(tt1+theta),'g')
quiver(B_cd(1),B_cd(2),fa(1),fa(2),'b')

quiver(C(1),C(2),fc(1),0,'r')     % C x
quiver(C(1),C(2),0,fc(2),'r')     % C y
quiver(C(1),C(2),fc(1),fc(2),'g')     % C xy

hold off
%%
figure
hold on
plot(M1(1),M1(2),'r.')
plot(M2(1),M2(2),'r.')
for i=-90 : 90
    for j=-90 : 90
        t1 = i;
        t2 = j;
        [t2, t2pd] = t1tot2(t1,M1,M2,a,b,c,d); % Parallel calc
        Q = fingerCalc(M1, M2, [0 0 t1 t2 a b c d e]);
        A = [Q(1) Q(2)];
        B = [Q(3) Q(4)];
        C = [Q(5) Q(6)];
        E = [Q(7) Q(8)];

        if sum([norm(A-M2) norm(B-A) norm(C) norm(B-C)]) ~= sum([Px(5:end-1)])
    %         plot([M2(1) A(1)],[M2(2) A(2)]) % a
    %         plot([A(1) B(1)],[A(2) B(2)]) % b
    %         plot([C(1) B(1)],[C(2) B(2)]) % d
    %        t1
            continue
        end
        %plot([M2(1) A(1)],[M2(2) A(2)]) % a
        %plot([A(1) B(1)],[A(2) B(2)]) % b
        %plot([M1(1) C(1)],[M1(2) C(2)]) % c
        %plot([C(1) B(1)],[C(2) B(2)]) % d
        plot([C(1) E(1)], [C(2) E(2)],'r') % e
        %plot(E(1),E(2),'r.')
        xlim([-100 100])
        ylim([-100 100])
        drawnow limitrate
    end
end

hold off

% norm(CB)
% norm(AB)
% [a b c d]
%[norm(A-M2) norm(B-A) norm(C) norm(B-C)]
%rad2deg(q_1)
