clc
clear all
close all

desiredPosition = [0,0];
desiredAngle = 60;
[motorAngles] = inverseKinematicsPreshape(desiredPosition,desiredAngle);



[jointPositionA] = forwardKinematics([0,0],motorAngles(2),motorAngles(3));