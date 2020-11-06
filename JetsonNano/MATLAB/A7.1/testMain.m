clc
clear all
close all
originalImage = imread('Test5.jpg');   
originalImage = imresize(originalImage,[3280,2464]);
originalImage = imresize(originalImage,0.3);



%% 
clc

colourBalancedImage = colourBalance(originalImage);

figure;
imshow(colourBalancedImage)
title('Colour balanced image');

roi = drawcrosshair('Color','r'); 

centerOfObjectX = round(roi.Position(2));
centerOfObjectY = round(roi.Position(1));


tic

colourSegmentationMask = colourSegmentation(colourBalancedImage,centerOfObjectX,centerOfObjectY);

segmentationMask = morphologicalFilters(colourSegmentationMask, centerOfObjectX, centerOfObjectY);

toc

figure;
imshow(segmentationMask)
title('Colour balanced image');

