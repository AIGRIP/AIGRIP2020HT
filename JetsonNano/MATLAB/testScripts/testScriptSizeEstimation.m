clear all
clc
close all

%add required functions and images
addpath('getRealSize');

distanceToObject = 200;
centerPointPixel = [0 0];
edgePointsPixel = [3 9;-7 -13 ;2 4;-1 -20 ;5 6];


edgePointsmm = GetPixelLength( centerPointPixel ,edgePointsPixel ,distanceToObject);








