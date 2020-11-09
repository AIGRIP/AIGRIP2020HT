clf; % clears plot

M1 = [0 0]; % Motor 1 position
M2 = M1 + [50 -20]; % Motor 2, relativ to Motor 1
t1 = -20; 
t2 = 10;

t1 = deg2rad(t1);
t2 = deg2rad(t2);

m2_start_ang = 0; % Starting angel of motor 2

% Phalanx and leaver-lengs in mm
a = 20;
b = 60;
c = 50;
d = 50;
ef = 40;

A = [M2(1)+a*cos(t2) M2(2)+a*sin(t2)];
C = [M1(1)+(c*-sin(t1)) M1(2)+(c*cos(t1))];

e = norm(M2-M1);
gamma = atan(abs(M2(2))/abs(M2(1)));
gamma_1 = pi/2 - gamma;
lambda_1 = pi - gamma - t2;
f = sqrt(e^2+a^2-(2*a*e*cos(lambda_1)));

lambda_2 = asin((sin(lambda_1)*e)/f);
lambda_3 = pi - lambda_1 - lambda_2;
fi = t1 + pi - gamma_1 - lambda_3;

g = sqrt(c^2+f^2-2*c*f*cos(fi));
g2 = norm(C-A);
fi_1 = asin(sin(fi)*f/g);
fi_2 = pi - fi_1 - fi;

beta = acos((-g^2 + b^2 + d^2)/(2*b*d));
beta_1 = asin(sin(beta)*b/g);
beta_2 = pi - beta_1 - beta;

q_2 = pi -(lambda_2 + fi_2 + beta_2);


B = [b*cos(t2+q_2)+a*cos(t2)+M2(1) b*sin(t2+q_2)+a*sin(t2)+M2(2)];

%E = [C(1)+(ef*-sin()) C(2)];

% Q = A - C;
% q = norm(Q); % length of q
% beta = (q^2 + b^2 + d^2)/(2*b*d); % Angle of beta at point B in rad
% alfa_1 = asin((sin(beta)*d)/q);
% fi_1 = asin((sin(beta)*b)/q);
% dp = abs(Q(1));
% bp = abs(Q(2));

% A_B_ang = deg2rad(90) + deg2rad(m2_ang) - atan(dp/bp) + alfa_1; % rad
% AB_rest = deg2rad(90) + deg2rad(m2_ang) - A_B_ang;  % rad
% C_B_ang = deg2rad(90) - deg2rad(m1_ang) - atan(bp/dp) + fi_1;   % rad

% B coordinates calculation
% CB = [C(1)+(sin(C_B_ang)*d) C(2)-(cos(C_B_ang)*d)];
% AB = [A(1)-(sin(AB_rest)*b) A(2)+(cos(AB_rest)*b)];

hold on
%plot(COR(M1,M2,'x'),COR(M1,M2,'y')) % plotting line from motor 1 to motor 2
plot([M2(1) A(1)],[M2(2) A(2)]) % a
plot([A(1) B(1)],[A(2) B(2)]) % b
plot([M1(1) C(1)],[M1(2) C(2)]) % c
plot([C(1) B(1)],[C(2) B(2)]) % d
%plot([M1(1) M1] []) % e

xlim([-75 100])
ylim([-75 100])
hold off

% norm(CB)
% norm(AB)
% [a c b d]
[norm(A-M2) norm(C) norm(B-A) norm(B-C)]