% graph generator
clf ; % clears plot
close all
clear;
clc

x = 1:160; % mm
a = 25; % mm
b = 85;
c = 60;
d = 40;
e = 50;
de = 25;
M1 = [0 0]; % Motor 1 position
M2 = M1 + [29 -38]; % Motor 2, relativ to Motor 1

t1mm = [-30 56]; % t1 max min
%t2mm = [-30 30]; % t2 max min
t1 = deg2rad(t1mm(1):t1mm(2));
%t2 = deg2rad(t2mm(1):t2mm(2));

% FRICTION PARAMETERS --------
a_tol = 0;  % added acceleration then moving object
sf = 1.5;     % safty factor
my = 0.85;  % friction
% ----------------------------

Dim = [M1,M2,a,b,c,d,e,de];
[FN,FD,M2r,t2p] = force_calc(Dim,t1,1); % rarallel: par = 1, else 0

T = xlsread('B.2.2.1.1 Objects define.xlsx');
T = [T(2:(1+T(1,11)),3), T(2:(1+T(1,11)),7),T(2:(1+T(1,11)),9), T(2:(1+T(1,11)),10)];
Ff = friction_calc(T,a_tol,sf,my);

palm_w = 100;

hold on
title('Finger Performance Graph')
xlim([0 200])
ylim([0 100])
plot(palm_w+2*FN(2,:),FN(1,:))
plot(Ff(1,:),Ff(2,:),'o')
plot(x,((2700e-9.*(x.^3))*(9.82+a_tol)*sf)./(2*my))
plot(x,((998e-9.*(x.^3))*(9.82+a_tol)*sf)./(2*my))
plot(x,((7870e-9.*(x.^3))*(9.82+a_tol)*sf)./(2*my))
xlabel('Grasping width [mm]')
ylabel('Exerted force [N]')
quiver(100,32,0,-5,'r')
text(88,35,'Max object')
%text(160,40,'FN')
text(110,80,'Fe')
text(150,70,'Al')
text(160,30,'H2O')
text(5,95,['ID: ' num2str(sf) ':' num2str(my) ':' num2str(a) '.' num2str(b) '.' num2str(c) '.' num2str(d) '.' num2str(e)])

filename = ['pic\FPG\FPG-' num2str(sf) '_' num2str(my) '_' num2str(a) '_' num2str(b) '_' num2str(c) '_' num2str(d) '_' num2str(e) '.png'];
saveas(gcf,filename)