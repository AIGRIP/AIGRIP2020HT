clear all;
close all;
clc;

addpath('..\A7.1');
addpath('..\A7.1\testImages\');

originalImage = imread("CUDATest.jpg");

imagePixelRows = size(originalImage,1);
imagePixelColumns = size(originalImage,2);

colourBalancedImage = colourBalance(originalImage);

centerOfObjectX = round( imagePixelRows/2 );
centerOfObjectY = round( imagePixelColumns/2 );

colourSegmentationMask = colourSegmentation(colourBalancedImage,centerOfObjectX,centerOfObjectY);

segmentationMask = morphologicalFilters(colourSegmentationMask, centerOfObjectX, centerOfObjectY);



figure(1)
subplot(1,2,1),imshow(segmentationMask);

% Edge filter work as expected.
[edgeBinaryImage] = MorphologicalEdgeFilter(segmentationMask);

subplot(1,2,2),imshow(edgeBinaryImage);
hold on;
subplot(1,2,2),scatter(centerOfObjectY,centerOfObjectX);

resDeg = 1*pi/180;
degreesToMeasure = 0:resDeg:(2*pi-resDeg);

[signature,yCoordinates,xCoordinates] = GetSignature(edgeBinaryImage,degreesToMeasure,imagePixelRows,imagePixelColumns);


figure(2)
subplot(1,2,1),plot(degreesToMeasure*180/pi,signature);
axis([0,360,0,600]);

cEdge = linspace(1,10,length(degreesToMeasure));
subplot(1,2,2),scatter(-1*yCoordinates,xCoordinates,25,cEdge);
hold on
subplot(1,2,2),scatter(0,0,50,'k','filled');
hold off
axis([-600,600,-600,600]);


[targetPointF1Y,targetPointF1X, normalPointF1Y,normalPointF1X, ...
    targetPointF2Y,targetPointF2X, normalPointF2Y,normalPointF2X, ...
    signatureF1,signatureF2] = ...
    stableLine(degreesToMeasure,yCoordinates,xCoordinates,signature);


figure(3)

plot(-1*targetPointF1Y,targetPointF1X,'r')
hold on
plot(-1*targetPointF2Y,targetPointF2X,'b')


cPrior = linspace(1,10,length(targetPointF2Y));
scatter(-1*targetPointF1Y,targetPointF1X,50,cPrior,'filled')
scatter(-1*normalPointF1Y,normalPointF1X,'r','x')
scatter(-1*targetPointF2Y,targetPointF2X,50,cPrior,'filled')
scatter(-1*normalPointF2Y,normalPointF2X,'b','x')


plot([-1*targetPointF1Y,-1*normalPointF1Y]',[targetPointF1X,normalPointF1X]','k')
plot([-1*targetPointF2Y,-1*normalPointF2Y]',[targetPointF2X,normalPointF2X]','k')
hold off
axis([-600,600,-600,600]);


figure(2)
hold on
subplot(1,2,2),scatter(-1*targetPointF1Y(1),targetPointF1X(1),60,'r','filled');
subplot(1,2,2),scatter(-1*targetPointF2Y(1),targetPointF2X(1),60,'r','filled');
subplot(1,2,2),scatter(-1*yCoordinates(1),xCoordinates(1),60,'r','filled');
hold off


