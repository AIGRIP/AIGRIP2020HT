clear;
clc;

addpath('..\A7.1');
addpath('..\A7.1\testImages\');

originalImage = imread("CUDATest.jpg");

imagePixelRows = size(originalImage,1);
imagePixelColumn = size(originalImage,2);

colourBalancedImage = colourBalance(originalImage);

centerOfObjectX = round( imagePixelRows/2 );
centerOfObjectY = round( imagePixelColumn/2 );

colourSegmentationMask = colourSegmentation(colourBalancedImage,centerOfObjectX,centerOfObjectY);

segmentationMask = morphologicalFilters(colourSegmentationMask, centerOfObjectX, centerOfObjectY);



figure
subplot(1,2,1),imshow(segmentationMask);

% Edge filter work as expected.
[edgeBinaryImage] = MorphologicalEdgeFilter(segmentationMask);

subplot(1,2,2),imshow(edgeBinaryImage);
hold on;
subplot(1,2,2),scatter(centerOfObjectY,centerOfObjectX);

resDeg = 1*pi/180;
degreesToMeasure = 0:resDeg:(2*pi-resDeg);

signature = GetSignature(edgeBinaryImage,degreesToMeasure,imagePixelRows,imagePixelColumn);


figure
plot(degreesToMeasure*180/pi,signature);
axis([0,360,0,600]);


%stableLine = stableLine(signature,degreesToMeasure)


