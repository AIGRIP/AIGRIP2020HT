clc
clear all
close all

desiredPosition = [70,80];
desiredAngle = [50,60];
[motorAngles] = inverseKinematicsPreshape(desiredPosition,desiredAngle)



[jointPositionA] = forwardKinematics([0,0],motorAngles(2),motorAngles(3));


%% 

clc
clear all
close all

pt = [3,1];
v1 = [0,3 ; 0,3 ; 0,3]
v2 = [0,5 ; 4,3 ; 2,0];


d = point_to_line(pt, v1, v2)

scatter(v2(:,1),v2(:,2))
