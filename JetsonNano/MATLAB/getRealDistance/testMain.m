clc
clear all
close all
originalImage = imread('binaryImage.jpg');   
% originalImage = imresize(originalImage,[3280,2464]);
% originalImage = imresize(originalImage,0.3);

originalImage= imbinarize(originalImage);

%% 
clc
close all


figure;
imshow(originalImage)
title('Colour balanced image');

objectMidPoint = 984/2;
distanceToObject = 600;
[lengthPixel,realObjectWidth] = GetPixelLength(originalImage, objectMidPoint, distanceToObject )








