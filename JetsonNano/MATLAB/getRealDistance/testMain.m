clc
clear all
close all
originalImage = imread('binaryImage200.jpg');   
% originalImage = imresize(originalImage,[3280,2464]);
% originalImage = imresize(originalImage,0.3);

originalImage= imbinarize(originalImage);

%% 
clc
close all


figure;
imshow(originalImage)
title('Colour balanced image');


distanceToObject = 200;
centerPointPixel = [0 0];
edgePointsPixel = [3 9;-7 -13 ;2 4;-1 -20 ;5 6];


edgePointsmm = GetPixelLength( centerPointPixel ,edgePointsPixel ,distanceToObject);








