
clf; % clears plot

M1 = [0 0]; % Motor 1 position
M2 = M1 + [50 -20]; % Motor 2, relativ to Motor 1
m1_ang = -20; 
m2_ang = 30;
m2_start_ang = 0; % Starting angel of motor 2

% Phalanx and leaver-lengs in mm
a = 20;
b = 60;
c = 50;
d = 50;
e = 50;

A = [M2(1)+a*cos(deg2rad(m2_ang+m2_start_ang)) M2(2)+a*sin(deg2rad(m2_ang+m2_start_ang))];
B = 0;
C = [M1(1)+(c*-sin(deg2rad(m1_ang))) M1(2)+(c*cos(deg2rad(m1_ang)))];
E = 0;

Q = A - C;
q = norm(Q); % length of q
beta = acos((-q^2 + b^2 + d^2)/(2*b*d)); % Angle of beta at point B in rad # la till acos #
alfa_1 = asin((sin(beta)*d)/q);
fi_1 = asin((sin(beta)*b)/q);
dp = abs(Q(1));
bp = abs(Q(2));

A_B_ang = deg2rad(90) + deg2rad(m2_ang) - atan(dp/bp) + alfa_1; % rad
AB_rest = deg2rad(90) + deg2rad(m2_ang) - A_B_ang;  % rad
C_B_ang = deg2rad(90) - deg2rad(m1_ang) - atan(bp/dp) + fi_1;   % rad

% B coordinates calculation
CB = [C(1)+(sin(C_B_ang)*d) C(2)-(cos(C_B_ang)*d)];
AB = [A(1)-(sin(AB_rest)*b) A(2)+(cos(AB_rest)*b)];

hold on
%plot(COR(M1,M2,'x'),COR(M1,M2,'y')) % plotting line from motor 1 to motor 2
plot([M2(1) A(1)],[M2(2) A(2)]) % a
plot([A(1) AB(1)],[A(2) AB(2)]) % b
plot([M1(1) C(1)],[M1(2) C(2)]) % c
plot([C(1) CB(1)],[C(2) CB(2)]) % d
%plot([M1(1) M1] []) % e

xlim([-75 100])
ylim([-75 100])
hold off

norm(CB)
norm(AB)