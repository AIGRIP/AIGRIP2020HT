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


desiredPosition = [5,10];
desiredAngle = [9,10];

[motorAngles] = InverseKinematicsPreshape(linkLengths, desiredPosition, desiredAngle)
% 
% [jointPositions , opticalSensorPosition] = ForwardKinematics(linkLengths,[20,10],motorAngles(2),motorAngles(3));
% % 
% % 
% %% 
% clc
% clear all
% close all
% pt = [30,30];
% v1 = [1,3];
% v2 = [1,5];
% 
%  d = PointToLine(pt, v1, v2);
% % 
% % 
% % 
% % 
% 
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


%[motorAnglet2] = ParallelMotorAnglet2(motorAnglet1,motorPositionM1,motorPositionM2,linkLengths);

[jointPositions] = ForwardKinematics(linkLengths,motorPositionM1,motorAnglet1,motorAnglet2)
% 
% 









