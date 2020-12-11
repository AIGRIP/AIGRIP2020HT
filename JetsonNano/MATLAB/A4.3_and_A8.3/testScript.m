clear all;
clc;

% addpath('..\A4.2');
% addpath('..\A7.1');
% addpath('..\A7.1\testImages\');
% addpath('..\getRealDistance\');

% originalImage = imread("CUDATest.jpg");

originalImage = imread("binaryImage600.jpg");
colourSegmentationMask = originalImage;
distanceToObject = 600;

imagePixelRows = size(originalImage,1);
imagePixelColumns = size(originalImage,2);

centerOfObjectX = round( imagePixelRows/2 );
centerOfObjectY = round( imagePixelColumns/2 );

offset = 10;

% colourBalancedImage = colourBalance(originalImage);
% 
% colourSegmentationMask = colourSegmentation(colourBalancedImage,centerOfObjectX,centerOfObjectY);

figure(1)
subplot(1,2,1),imshow(colourSegmentationMask);

colourSegmentationMask = imbinarize(colourSegmentationMask);

[errorNoImage, edgeBinaryImage] = MorphologicalFilters(colourSegmentationMask, centerOfObjectX, centerOfObjectY);
if errorNoImage == 1
   disp("No item") 
end
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
    targetPointF0Y,targetPointF0X,normalPointF0Y,normalPointF0X, ...
    signatureF1,signatureF2] = ...
    StableLine(degreesToMeasure,yCoordinates,xCoordinates,signature);


figure(2)
hold on
subplot(1,2,2),scatter(-1*targetPointF1Y(1),targetPointF1X(1),60,'r','filled');
subplot(1,2,2),scatter(-1*targetPointF2Y(1),targetPointF2X(1),60,'r','filled');
subplot(1,2,2),scatter(-1*yCoordinates(1),xCoordinates(1),60,'r','filled');
hold off

figure(3)

plot(-1*targetPointF1Y,targetPointF1X,'r')
hold on
plot(-1*targetPointF2Y,targetPointF2X,'b')


cPrior = linspace(1,10,length(targetPointF2Y));
scatter(-1*targetPointF1Y,targetPointF1X,50,cPrior,'filled')
scatter(-1*normalPointF1Y,normalPointF1X,'r','x')
scatter(-1*targetPointF2Y,targetPointF2X,50,cPrior,'filled')
scatter(-1*normalPointF2Y,normalPointF2X,'b','x')

scatter(-1*targetPointF0Y,targetPointF0X,'b','filled')
scatter(-1*normalPointF0Y,normalPointF0X,'c','x')
plot([-1*targetPointF0Y,-1*normalPointF0Y]',[targetPointF0X,normalPointF0X]','k')

plot([-1*targetPointF1Y,-1*normalPointF1Y]',[targetPointF1X,normalPointF1X]','k')
plot([-1*targetPointF2Y,-1*normalPointF2Y]',[targetPointF2X,normalPointF2X]','k')
hold off
axis([-600,600,-600,600]);

% Get valid points
[motorStepF1,BestPointF1Y,BestPointF1X,BestNormalF1Y,BestNormalF1X] = ...
GetValidGripPoints(targetPointF1Y,targetPointF1X, normalPointF1Y,normalPointF1X,distanceToObject,1,offset);

% Get valid points
[motorStepF2,BestPointF2Y,BestPointF2X,BestNormalF2Y,BestNormalF2X] = ...
GetValidGripPoints(targetPointF2Y,targetPointF2X, normalPointF2Y,normalPointF2X,distanceToObject,2,offset);


% Get valid points
[motorStepF0,BestPointF0Y,BestPointF0X,BestNormalF0Y,BestNormalF0X] = ...
GetValidGripPoints(targetPointF0Y,targetPointF0X, normalPointF0Y,normalPointF0X,distanceToObject,0,offset);

figure(4)

scatter(0,0,40,'k','filled');
hold on
scatter(BestPointF1X,BestPointF1Y,40,'r','filled');
scatter(BestPointF2X,BestPointF2Y,40,'r','filled');
scatter(BestPointF0X,BestPointF0Y,40,'r','filled');

scatter(0,0,40,'k','filled');
scatter(-23,36,40,'k','filled');
scatter(-23,-36,40,'k','filled');

for i=1:length(targetPointF2Y)
   scatter(-GetPixelLength( 0 ,targetPointF2Y(i) ,distanceToObject ) ...
,GetPixelLength( 0 ,targetPointF2X(i) ,distanceToObject ) ) 

   scatter(-GetPixelLength( 0 ,targetPointF1Y(i) ,distanceToObject ) ...
,GetPixelLength( 0 ,targetPointF1X(i) ,distanceToObject ) ) 
end

plot(-1*GetPixelLength(0,yCoordinates,distanceToObject),GetPixelLength(0,xCoordinates,distanceToObject),'r')


hold off

disp('Motorvalue Finger 0')
disp(motorStepF0)

disp('Motorvalue Finger 1')
disp(motorStepF1)

disp('Motorvalue Finger 2')
disp(motorStepF2)

