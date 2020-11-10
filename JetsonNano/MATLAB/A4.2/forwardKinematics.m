function [jointPositionA] = forwardKinematics(motorPositionM1,motorAnglet1,motorAnglet2)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

% system_model

%motorPostionM1 = [0 0]; % Motor 1 position
motorPositionM2 = motorPositionM1 + [29 -38]; % Motor 2, relativ to Motor 1

motorAnglet1 = deg2rad(motorAnglet1); 
motorAnglet2 = deg2rad(motorAnglet2);

% Phalanx and leaver-lengths in mm
linkLengtha = 25;
linkLengthb = 95;
linkLengthc = 60;
linkLengthd = 35;
linkLengthe = 50;



% normAC = norm(A-C)
normAC = sqrt((motorPositionM2(1)+linkLengtha*cos(motorAnglet2)+motorPositionM1(1)+linkLengthc*sin(motorAnglet1))^2+(motorPositionM2(2)+linkLengtha*sin(motorAnglet2)+motorPositionM1(2)-linkLengthc*cos(motorAnglet1))^2);
normAM1 = sqrt((motorPositionM2(1)+linkLengtha*cos(motorAnglet2)-motorPositionM1(1))^2+(motorPositionM2(2)+linkLengtha*sin(motorAnglet2)-motorPositionM1(2))^2);
normCM2 = sqrt((motorPositionM2(1)-motorPositionM1(1)+linkLengthc*sin(motorAnglet1))^2+(motorPositionM2(2)-motorPositionM1(2)-linkLengthc*cos(motorAnglet1))^2);

thetaL = acos((linkLengthc^2+normAC^2-normAM1^2)/(2*linkLengthc*normAC));
alfaL = acos((normAC^2+linkLengtha^2-normCM2^2)/(2*normAC*linkLengtha));
thetaV = acos((normAC^2+linkLengthd^2-linkLengthb^2)/(2*normAC*linkLengthd));
alfaV = acos((linkLengthb^2+normAC^2-linkLengthd^2)/(2*linkLengthb*normAC));

angleTheta = thetaL + thetaV;
angleAlfa = alfaL + alfaV;
angleBeta = acos((linkLengthd^2+linkLengthb^2-normAC^2)/(2*linkLengthd*linkLengthb));

%  --- Angels and coordinates calculations
jointPositionA = [motorPositionM2(1)+linkLengtha*cos(motorAnglet2) motorPositionM2(2)+linkLengtha*sin(motorAnglet2)];
jointPositionB = [motorPositionM2(1)+linkLengtha*cos(motorAnglet2)+linkLengthb*cos(pi-angleAlfa+motorAnglet2) motorPositionM2(2)+linkLengtha*sin(motorAnglet2)+linkLengthb*sin(pi-angleAlfa+motorAnglet2)];
jointPositionC = [motorPositionM1(1)+(linkLengthc*-sin(motorAnglet1)) motorPositionM1(2)+(linkLengthc*cos(motorAnglet1))];
jointPositionE = [motorPositionM1(1)-linkLengthc*sin(motorAnglet1)+linkLengthe*sin((pi/2)-angleTheta-motorAnglet1) motorPositionM1(2)+linkLengthc*cos(motorAnglet1)+linkLengthe*cos((pi/2)-angleTheta-motorAnglet1)];
mouseSensorPosition = [motorPositionM1(1)-linkLengthc*sin(motorAnglet1)+(linkLengthe/2)*sin((pi/2)-angleTheta-motorAnglet1) motorPositionM1(2)+linkLengthc*cos(motorAnglet1)+(linkLengthe/2)*cos((pi/2)-angleTheta-motorAnglet1)]; % point of exerted force on upper phalanx

joint = [motorPositionM1 ; motorPositionM2 ; jointPositionA ; jointPositionB ; jointPositionC ; jointPositionE]';
scatter(joint(1,:),joint(2,:))
A = ["M1","M2","A","B","C","E"];
textPoints = cellstr(A);
text(joint(1,:),joint(2,:),textPoints)

end

