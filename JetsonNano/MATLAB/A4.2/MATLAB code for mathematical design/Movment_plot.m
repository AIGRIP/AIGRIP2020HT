% Movment plot
clf ; % clears plot
close all
clear;
clc

% Phalanx and leaver-lengs in mm
a = 25; % mm
b = 85;
c = 60;
d = 40;
e = 50;
de = 25;
M1 = [0 0]; % Motor 1 position
M2 = M1 + [29 -38]; % Motor 2, relativ to Motor 1

t1mm = [-30 56]; % t1 max min
t1 = deg2rad(t1mm(1):t1mm(2));


figure
hold on
plot(M1(1),M1(2),'r.')
plot(M2(1),M2(2),'r.')
plot([-50 -50],[0 100],'b') %stop
for i = 1 : length(t1)
    [t2, t2pd] = t1tot2(t1(i),M1,M2,a,b,c,d); % Parallel calc
    t2s(i)=t2;  
    Q = fingerCalc(M1, M2, [0 0 t1(i) t2 a b c d e]);
    A = [Q(1) Q(2)];
    B = [Q(3) Q(4)];
    C = [Q(5) Q(6)];
    E = [Q(7) Q(8)];

    plot([M2(1) A(1)],[M2(2) A(2)]) % a
    plot([A(1) B(1)],[A(2) B(2)]) % b
    plot([M1(1) C(1)],[M1(2) C(2)]) % c
    plot([C(1) B(1)],[C(2) B(2)]) % d
    plot([C(1) E(1)], [C(2) E(2)],'r') % e
    plot(E(1),E(2),'r.')
    xlim([-100 100])
    ylim([-80 120])
    drawnow limitrate
end
title('Parallel Movment Graph')
xlabel('coordinates: x axis [mm]')
ylabel('coordinates: y axis [mm]')
text(-95,110,['ID: ' num2str(a) '.' num2str(b) '.' num2str(c) '.' num2str(d) '.' num2str(e)])

filename = ['pic\PMG\PMG-' num2str(a) '_' num2str(b) '_' num2str(c) '_' num2str(d) '_' num2str(e) '.png'];
saveas(gcf,filename)