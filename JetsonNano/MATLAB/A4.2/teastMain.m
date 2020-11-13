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


desiredPosition = [70,70];
desiredAngle = [-100000,-1];
[motorAngles] = inverseKinematicsPreshape(linkLengths, desiredPosition, desiredAngle)



%%[jointPositionA] = forwardKinematics([0,0],motorAngles(2),motorAngles(3));


%% 

clc
clear all
close all

pt = [3,1];
v1 = [1,3];
v2 = [1,5];


d = point_to_line(pt, v1, v2);

figure
scatter(v2(1,1),v2(1,2))
hold on
scatter(v1(1,1),v1(1,2))
hold on
scatter(pt(1,1),pt(1,2))






















