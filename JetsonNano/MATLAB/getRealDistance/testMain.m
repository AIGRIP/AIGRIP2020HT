clc
clear all
close all
originalImage = imread('binaryImage400.jpg');   
% originalImage = imresize(originalImage,[3280,2464]);
% originalImage = imresize(originalImage,0.3);

originalImage= imbinarize(originalImage);

%% 
clc
close all


figure;
imshow(originalImage)
title('Colour balanced image');

objectMidPoint = 400;
distanceToObject = 400;
[lengthPixel,realObjectWidth] = GetPixelLength(originalImage, objectMidPoint, distanceToObject )








