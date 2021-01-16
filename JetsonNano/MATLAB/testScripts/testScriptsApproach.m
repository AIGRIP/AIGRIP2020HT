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

currentMotorM0Steps = 20000;
currentMotorM1Steps = 50000;
distanceToObject = 20;

[motorAngles] = ApproachObject(linkLengths,uint16(currentMotorM0Steps), uint16(currentMotorM1Steps),distanceToObject);