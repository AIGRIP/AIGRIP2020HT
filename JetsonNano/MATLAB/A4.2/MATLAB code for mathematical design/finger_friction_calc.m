%based on: 
%http://www.intelligentactuator.com/partsearch/robocylinder/appndx74_Model_Selection_by_RCP2_Gripper.pdf

m = 0.2:0.1:12; % object mass
g = 9.82; % gravitation
a = 0;  %accceleration (movment)
s_f = 1; % safty factor
my = 0.85; % friction
f_l = 0.06; % finger length im meter

% Fm - force req. for hold object. 
% Fm = mass * (gravity * acceleration) * safty factor / friction
Fm = (m*(g+a)*s_f)./my;

% Divide force between 3 fingers
Ff = Fm./2;

% Convet to torque
T = Ff*f_l;

% slipage something
bs  = (m*1.4.^2)./(2*22);

plot(m,T)
xlabel('Object weight [Kg]')
ylabel('Required motor torque [Nm]')
T(29) % torque for 3 kg
Ff(29)

figure
plot(m,Ff)
xlabel('Object weight [Kg]')
ylabel('Required finger force [N]')


%figure
%plot(m,bs*100)
%xlabel('Object weight [Kg]')
%ylabel('Breaking length [cm]')
