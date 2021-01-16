clc
clear all
close all

%add required functions and images
addpath('images/testImagesSegmentation','segmentation');

originalImage = imread("testImagesSegmentation/Test1.jpg");   
originalImage = imresize(originalImage,[3280,2464]);
originalImage = imresize(originalImage,0.3);



%% 
clc
%Change the image to BGR
originalImageBGR = cat(3, originalImage(:,:,3), originalImage(:,:,2), originalImage(:,:,1));

colourBalancedImage = ColourBalance(originalImageBGR);

%Choose where hte object is
figure;
imshow(colourBalancedImage)
title('Colour balanced image');
impixelinfo
roi = drawcrosshair('Color','r'); 

centerOfObjectX = round(roi.Position(2));
centerOfObjectY = round(roi.Position(1));

colourSegmentationMask = ColourSegmentation(colourBalancedImage,centerOfObjectX,centerOfObjectY);

[errorNoImage,segmentationMask] = MorphologicalFilters(colourSegmentationMask, centerOfObjectX, centerOfObjectY);

figure;
imshow(segmentationMask)
title('Colour balanced image');

