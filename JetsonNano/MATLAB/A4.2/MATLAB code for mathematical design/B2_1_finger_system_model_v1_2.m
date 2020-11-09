% system_model
clf ; % clears plot
close all
clear;
clc

M1 = [0 0]; % Motor 1 position
M2 = M1 + [29 -38]; % Motor 2, relativ to Motor 1
t1 = deg2rad(0); 
t2 = deg2rad(60); % alltid paralle nu
% a vinkelrät med b om: t1=-24, t2=0 

M1t = 1.5;  % Motor torque [Nm]
M2t = 1.5;  %
delta_e = 25; % contact point on upper phalanx

% text format
fo = '%.1f';

% Phalanx and leaver-lengs in mm
% a = 20;
% b = 70;
% c = 50;
% d = 30;
% e = 30;
a = 25;
b = 85;
c = 60;
d = 35;
e = 50;

[t2, t2pd] = t1tot2(t1,M1,M2,a,b,c,d); % Parallel calc

%  --- Angels and coordinates calculations
A = [M2(1)+a*cos(t2) M2(2)+a*sin(t2)];
C = [M1(1)+(c*-sin(t1)) M1(2)+(c*cos(t1))];

% g = norm(A-C)
g = sqrt((M2(1)+a*cos(t2)+M1(1)+c*sin(t1))^2+(M2(2)+a*sin(t2)+M1(2)-c*cos(t1))^2);
g_1 = sqrt((M2(1)+a*cos(t2)-M1(1)+c*sin(t1))^2+(M2(2)+a*sin(t2)-M1(2)-c*cos(t1))^2);
g_2 = norm(A-C); % test

beta = acos((d^2+b^2-g^2)/(2*d*b));

AM1 = sqrt((M2(1)+a*cos(t2)-M1(1))^2+(M2(2)+a*sin(t2)-M1(2))^2);

CM2 = sqrt((M2(1)-M1(1)+c*sin(t1))^2+(M2(2)-M1(2)-c*cos(t1))^2);

thetaL = acos((c^2+g^2-AM1^2)/(2*c*g));
alfaL = acos((g^2+a^2-CM2^2)/(2*g*a));
thetaV = acos((g^2+d^2-b^2)/(2*g*d));
alfaV = acos((b^2+g^2-d^2)/(2*b*g));

theta = thetaL + thetaV;
alfa = alfaL + alfaV;

B = [M2(1)+a*cos(t2)+b*cos(pi-alfa+t2) M2(2)+a*sin(t2)+b*sin(pi-alfa+t2)]; % B_ab
%B_cd = [M1(1)-c*sin(t1)+d*sin(pi-theta-t1) M1(2)+c*cos(t1)+d*cos(pi-theta-t1)]; % B_cd

E = [M1(1)-c*sin(t1)+e*sin((pi/2)-theta-t1) M1(2)+c*cos(t1)+e*cos((pi/2)-theta-t1)];
dE = [M1(1)-c*sin(t1)+delta_e*sin((pi/2)-theta-t1) M1(2)+c*cos(t1)+delta_e*cos((pi/2)-theta-t1)]; % point of exerted force on upper phalanx

% PARALLEL ----------------------------------------
% based on: http://www.ryanjuckett.com/programming/analytic-two-bone-ik-in-2d/

% Parallel B based on t1 (C + d): 
% Bn = [M1(1)+(c*-sin(t1))+d  M1(2)+(c*cos(t1))] - M2; % C + d - M2
% alf = pi-acos((a^2+b^2-(norm(Bn))^2)/(2*a*b));
% 
% t2p = atan((((Bn(2)*(a+b*cos(alf)))-(Bn(1)*(b*sin(alf)))))/((Bn(1)*(a+b*cos(alf)))+(Bn(2)*(b*sin(alf)))));
% t2pd = rad2deg(t2p); % t2p in deg
% ----------------------------------------

%  --- Error
if abs(norm(A-M2)-a) > 0.01 || abs(norm(B-A)-b) > 0.01 || abs(norm(C)-c) > 0.01 || abs(norm(B-C)-d) > 0.01
    error('粪便');
end

%  --- Plot angels and coordinates
hold on
plot([M2(1) A(1)],[M2(2) A(2)]) % a
plot([A(1) B(1)],[A(2) B(2)]) % b
plot([M1(1) C(1)],[M1(2) C(2)]) % c
plot([C(1) B(1)],[C(2) B(2)]) % d
plot([C(1) E(1)], [C(2) E(2)]) % e
xlim([-50 100])
ylim([-40 110])
title('Finger And Lever Orientation')
text(-45,105,['ID: ' num2str(rad2deg(t1)) '.' num2str(rad2deg(t2)) '.' num2str(a) '.' num2str(b) '.' num2str(c) '.' num2str(d) '.' num2str(e)])

filename = ['pic\FALO' num2str(rad2deg(t1)) '_' num2str(rad2deg(t2)) '_' num2str(a) '_' num2str(b) '_' num2str(c) '_' num2str(d) '_' num2str(e) '.png'];
saveas(gcf,filename)


%figure
hold on
plot([0 d],[0 0]) % d
plot([0 0],[0 e]) % ful distal phalanx
plot([0 0],[0 delta_e]) % delat_e phalanx

%xlim([-25 60])
%ylim([-25 60])
title('Forces Exerted - Distal Phalnax')
text(-20,55,['ID: ' num2str(rad2deg(t1)) '.' num2str(rad2deg(t2)) '.' num2str(a) '.' num2str(b) '.' num2str(c) '.' num2str(d) '.' num2str(e)])

%  --- Static model
%ar = 0.3; % Arrow scalar

% fa = [cos(deg2rad(90)+t2) sin(deg2rad(90)+t2)]; % fax fay, force vector from motor 2 and lever a
% fa = fa*M2t/(0.001*a);
% fab = [norm(fa)*sin(pi-alfa)*-cos(alfa-t2) norm(fa)*sin(pi-alfa)*sin(alfa-t2)]; % ar*sin(pi-alfa) = magnituden av kraften
% 
% fc = -M1t/(0.001*c);
% fb = (0.001*delta_e*fc*-sin(theta))/((0.001*d*sin(beta))-(0.001*delta_e*cos(beta)));

%fa = [cos(deg2rad(90)+t2) sin(deg2rad(90)+t2)]; % fax fay, force vector from motor 2 and lever a
%fa = fa*M2t/(0.001*a); % not correct, placholder
%fab = [norm(fa)*sin(pi-alfa)*-cos(alfa-t2) norm(fa)*sin(pi-alfa)*sin(alfa-t2)]; % ar*sin(pi-alfa) = magnituden av kraften

%fc = M1t/(0.001*c)*[cos(pi+t1) sin(pi+t1)]; old based on t1. not relative
fc = M1t/(0.001*c)*[cos((3*pi/2)-theta) sin((3*pi/2)-theta)];
fb_r = (-fc(1)*delta_e)/((cos(beta)*delta_e)+(sin(beta)*d)); % force required to mentain parallel grip. mm inte m, convertering inte nödvändig
fbmax = (1.5*sin(pi-alfa))/(0.001*a);
fc_r = M1t/(0.001*c);
if fb_r > fbmax
    fb_r = fbmax;
    fc_r = -((cos(beta)*delta_e)+(sin(beta)*d))*fb_r/(cos((3*pi/2)-theta)*delta_e);
    fc = fc_r*[cos((3*pi/2)-theta) sin((3*pi/2)-theta)];
end
fb = fb_r*[cos(beta) sin(beta)];

%fb = (0.001*delta_e*fc*-sin(theta))/((0.001*d*sin(beta))-(0.001*delta_e*cos(beta)));

%dpr = [cos(theta-(pi/2)+t1) -sin(theta-(pi/2)+t1); sin(theta-(pi/2)+t1) cos(theta-(pi/2)+t1)]; % distal phalanx rotation
%quiver(C(1),C(2),-10*cos(theta-(pi/2)+t1),-10*sin(theta-(pi/2)+t1)) % test arrow

%fc = fc*dpr
%FN = fc*-sin(theta) + fb*cos(beta); % Draft 1 calc
FN = -fc(1)-fb(1);
FD = -fc(2)-fb(2);

% demanded tourque from motor 2, based on 'fb_r'
M2t_r = (fb_r*0.001*a)/sin(pi-alfa);
d_M2t_r = 100*M2t_r/M2t; % % of torque requred from M2

d_M1t_r = 100*(fc_r*c*0.001)/M1t;

% Arrows for simpel upper phalanx
quiver(d,0,fb(1),fb(2)) % fb
text(d,-5,['fb: ' num2str(norm(fb),fo) ' N'])

quiver(0,0,fc(1),fc(2)) % fc
text(0,-5,['fc: ' num2str(norm(fc),fo) ' N'])

quiver(0,delta_e, FN, 0) % FN
text(FN,delta_e,['FN: ' num2str(FN,fo) ' N'])


filename = ['pic\FEDP' num2str(rad2deg(t1)) '_' num2str(rad2deg(t2)) '_' num2str(a) '_' num2str(b) '_' num2str(c) '_' num2str(d) '_' num2str(e) '.png'];
saveas(gcf,filename)

% Arrows to gripper model
% quiver(dE(1),dE(2),FN*-sin(theta+t1),FN*cos(theta+t1),'r') % FN
% quiver(C(1),C(2),fc*sin(theta),fc*+cos(theta),'g'); % fc xy %% sin(theta)
% quiver(B(1),B(2),norm(fab)*-cos(alfa-t2),norm(fab)*sin(alfa-t2),'g'); % fb xy %% -cos(beta)

%quiver(0,0,10*+cos(beta),10*sin(beta))

% 
% fa = [cos(deg2rad(90)+t2) sin(deg2rad(90)+t2)]; % fax fay, force vector from motor 2 and lever a
% fa = fa*M2t/(0.001*a);
% fab = [norm(fa)*sin(pi-alfa)*-cos(alfa-t2) norm(fa)*sin(pi-alfa)*sin(alfa-t2)]; % ar*sin(pi-alfa) = magnituden av kraften
% fc = [cos(pi+t1) sin(pi+t1)];    % fcx fcy
% fc = fc*M1t/(0.001*c);
% fby = [norm(fab)*sin(Beta)*cos(t1+theta) norm(fab)*sin(Beta)*sin(t1+theta)]; % (storlek fab, xy uppdelning på led i x y, vinkel på led)
% fbx = [norm(fab)*-cos(Beta)*-sin(t1+theta) norm(fab)*-cos(Beta)*cos(t1+theta)];
% 
% 
% Fn = sin(theta)*norm(fc)+norm(fbx)+(d*norm(fby)/delta_e);
% 
% %quiver(A(1),A(2),ar*cos(deg2rad(90)+tt2),0)     % A x
% %quiver(A(1),A(2),0,ar*sin(deg2rad(90)+tt2))     % A y
% 
% quiver(A(1),A(2),fa(1)*ar,0,'r')     % A x
% quiver(A(1),A(2),0,fa(2)*ar,'r')     % A y
% quiver(A(1),A(2),fa(1)*ar,fa(2)*ar,'g')     % A xy
% quiver(A(1),A(2),fab(1)*ar,fab(2)*ar,'b')   % A 
% 
% 
% quiver(B(1),B(2),fab(1)*ar,0,'r')    % B x
% quiver(B(1),B(2),0,fab(2)*ar,'r')    % B y
% 
% quiver(B(1),B(2),fby(1)*ar,fby(2)*ar,'c')
% quiver(B(1),B(2),fbx(1)*ar,fbx(2)*ar,'g')
% quiver(B(1),B(2),fab(1)*ar,fab(2)*ar,'b')
% 
% quiver(C(1),C(2),fc(1)*ar,0,'r')     % C x
% quiver(C(1),C(2),0,fc(2)*ar,'r')     % C y
% quiver(C(1),C(2),fc(1)*ar,fc(2)*ar,'g')     % C xy

fprintf('Exerted force:          %.4f \nRequired force in B:    %.4f \nFD:              %.4f\n', FN, fb_r, FD)
fprintf('M1: %.4f Nm  %.0f %%\n',M1t ,d_M1t_r)
fprintf('M2: %.4f Nm  %.0f %%',M2t_r ,d_M2t_r)