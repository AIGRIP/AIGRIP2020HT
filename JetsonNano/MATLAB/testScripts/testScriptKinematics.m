clc
clear all
close all

%add required functions and images
addpath('kinematics','getGripPositions');

%Set length values for all links in model
linkLengtha = 25;
linkLengthb = 95;
linkLengthc = 60;
linkLengthd = 35;
linkLengthe = 50;

linkLengths = [linkLengtha, linkLengthb, linkLengthc, linkLengthd, linkLengthe];


desiredPosition = [-23,36];
desiredAngle = [30,0];
offset = 0; 

if PointToLine([-23,36], desiredPosition, desiredAngle) == 1
    

    [motorAngles] = InverseKinematicsPreshape(linkLengths, desiredPosition, desiredAngle,1, offset)

    motorAnglesDegree = motorAngles * (300/65535);

    motorAngles = motorAngles * (1023/65535);
end
[jointPositions , opticalSensorPosition] = ForwardKinematics(linkLengths,[20,10],double(motorAngles(2)),double(motorAngles(3)))



%%
clc
clear all
close all
%Set length values for all links in model
linkLengtha = 25;
linkLengthb = 95;
linkLengthc = 60;
linkLengthd = 35;
linkLengthe = 50;

linkLengths = [linkLengtha, linkLengthb, linkLengthc, linkLengthd, linkLengthe];
motorAnglet1 = 3/4;
motorAnglet2 = 1.2829;
motorPositionM1 = [0,0];
motorPositionM2 = [-29,-38];


[motorAnglet2] = ParallelMotorAnglet2(motorAnglet1,motorPositionM1,motorPositionM2,linkLengths);

[jointPositions , opticalSensorPosition] = ForwardKinematics(linkLengths,motorPositionM1,motorAnglet1,motorAnglet2)
% 
% 










