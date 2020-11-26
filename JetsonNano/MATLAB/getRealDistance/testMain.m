clc
clear all
close all
originalImage = imread('binaryImage600.jpg');   
% originalImage = imresize(originalImage,[3280,2464]);
% originalImage = imresize(originalImage,0.3);

originalImage= imbinarize(originalImage);

%% 
clc
close all


figure;
imshow(originalImage)
title('Colour balanced image');

objectMidPoint = 370;
distanceToObject = 600;
[lengthPixel,realObjectHeight] = GetPixelLength(originalImage, objectMidPoint, distanceToObject )








