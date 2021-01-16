close all; 
clear; 
clc;

%add required functions and images
addpath('laserScripts','images/testImagesLaser');

% Load image with laser line
imgOriginal = importdata('laserImage.jpg');

% Laser detection by applying a HSV filter
[bitMask, imgLaser] = LaserDetect(imgOriginal);

% Calculate laser line thickness for each column
laserThickness = ones(1 ,size(imgLaser,1)) * bitMask;

% Locate the top-most pixel of the laser for each column
[~, laserHeight]=max(bitMask);

% Calculate the central point of the line for each column
laserHeight = laserHeight + floor(laserThickness / 2);

% Generate bitmask the calculated central line
validationBitMask = zeros(size(bitMask));
validationBitMask(sub2ind(size(bitMask), laserHeight, 1:length(laserThickness))) = 1;

% Generate image for validation, set central line to 0 (black)
% for each colour representation (RGB)
imgValidation = imgLaser;
imgValidation(repmat(validationBitMask==1, [1 1 3])) = 0;

figure (1)
imshow(imgValidation)
title("Detected laser height shown as black centered line in the laser")

