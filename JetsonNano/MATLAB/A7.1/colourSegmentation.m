function [SegmentationMask] = colourSegmentation(colourBalancedImage,centerOfObjectX,centerOfObjectY)

%The function takes in a image and a rough postion of the object in the
%image that should be segmented. and it outputs a a bitmask of the the
%object.

%Input:
%colourBalancedImage = RGB image 984x740x3
%centerOfObjectX = Objects center postion in the x-axis
%centerOfObjectY = Objects center postion in the y-axis

%Output:
%SegmentationMask = bitmask of the segmented object


%Transform the Image into the HSV colour space
HSVImage = rgb2hsv(colourBalancedImage);

%Standardize the H-values from 0-1 to 0-360
HSVImage(:,:,1) = HSVImage(:,:,1) * 360;

%Make a small square at the center of the object and determine which 
%colour is most prevalent in the square

%Choose square size
squareSize = 51;
squareHalfSize = floor(squareSize/2);

%Calculate the start and end values for X and  Y
startX = centerOfObjectX - squareHalfSize;
endX = centerOfObjectX + squareHalfSize;
startY = centerOfObjectY - squareHalfSize;
endY = centerOfObjectY + squareHalfSize;

%Take out the sqaure area from the image
centerHSVImage = HSVImage(startX:endX , startY:endY ,:);

centerColourMask = zeros(squareSize , squareSize ,9,'logical');
%Make mask in the square for every 9 colours. 

%Calcualte which pixels are red
centerColourMask(:,:,1) = (centerHSVImage(:,:,1) < 15 | centerHSVImage(:,:,1) == 315 | centerHSVImage(:,:,1) > 315) & centerHSVImage(:,:,2) > 0.2 & centerHSVImage(:,:,3) > 0.3;
%Calcualte which pixels are orange
centerColourMask(:,:,2) = ((centerHSVImage(:,:,1) > 15 & centerHSVImage(:,:,1) < 50) | centerHSVImage(:,:,1) == 15) & centerHSVImage(:,:,2) > 0.2 & centerHSVImage(:,:,3) > 0.3;
%Calcualte which pixels are yellow
centerColourMask(:,:,3) = ((centerHSVImage(:,:,1) > 50 & centerHSVImage(:,:,1) < 70) | centerHSVImage(:,:,1) == 50) & centerHSVImage(:,:,2) > 0.2 & centerHSVImage(:,:,3) > 0.3;
%Calcualte which pixels are green
centerColourMask(:,:,4) = ((centerHSVImage(:,:,1) > 70 & centerHSVImage(:,:,1) < 155) | centerHSVImage(:,:,1) == 70) & centerHSVImage(:,:,2) > 0.2 & centerHSVImage(:,:,3) > 0.3;
%Calcualte which pixels are cyan
centerColourMask(:,:,5) = ((centerHSVImage(:,:,1) > 155 & centerHSVImage(:,:,1) < 205) | centerHSVImage(:,:,1) == 155) & centerHSVImage(:,:,2) > 0.2 & centerHSVImage(:,:,3) > 0.3;
%Calcualte which pixels are blue
centerColourMask(:,:,6) = ((centerHSVImage(:,:,1) > 205 & centerHSVImage(:,:,1) < 260) | centerHSVImage(:,:,1) == 205) & centerHSVImage(:,:,2) > 0.2 & centerHSVImage(:,:,3) > 0.3;
%Calcualte which pixels are purple
centerColourMask(:,:,7) = ((centerHSVImage(:,:,1) > 260 & centerHSVImage(:,:,1) < 315) | centerHSVImage(:,:,1) == 260) & centerHSVImage(:,:,2) > 0.2 & centerHSVImage(:,:,3) > 0.3;
%Calcualte which pixels are white
centerColourMask(:,:,8) = (centerHSVImage(:,:,3) > 0.6 | centerHSVImage(:,:,3) == 0.6) & (centerHSVImage(:,:,2) < 0.2 | centerHSVImage(:,:,2) == 0.2);
%Calcualte which pixels are black
centerColourMask(:,:,9) = centerHSVImage(:,:,3) < 0.3 | centerHSVImage(:,:,3) == 0.3 | (centerHSVImage(:,:,3) < 0.6 & (centerHSVImage(:,:,2) < 0.2 | centerHSVImage(:,:,2) == 0.2));

% Sum up all the masks and then determine which mask has the most pixels
voterCount = sum(centerColourMask,[1 2]);
voterCount = permute(voterCount,[1 3 2]);
voterCount = reshape(voterCount,[],size(voterCount,2),1);
[~,indexBiggest] = max(voterCount);

[imageWidth, imageHeight, ~]=size(colourBalancedImage);
colourSegmentationMask = zeros(imageWidth, imageHeight, 'logical');
% Make a mask over the whole image. The colour that is seperated
% is the one that had the most pixels in the square
if indexBiggest == 1
    %Red
    colourSegmentationMask = (HSVImage(:,:,1) < 15 | HSVImage(:,:,1) == 315 | HSVImage(:,:,1) > 315) & HSVImage(:,:,2) > 0.2 & HSVImage(:,:,3) > 0.3;
elseif indexBiggest == 2    
    %Orange
    colourSegmentationMask = ((HSVImage(:,:,1) > 15 & HSVImage(:,:,1) < 50) | HSVImage(:,:,1) == 15) & HSVImage(:,:,2) > 0.2 & HSVImage(:,:,3) > 0.3;
elseif indexBiggest == 3     
    %Yellow
    colourSegmentationMask = ((HSVImage(:,:,1) > 50 & HSVImage(:,:,1) < 70) | HSVImage(:,:,1) == 50) & HSVImage(:,:,2) > 0.2 & HSVImage(:,:,3) > 0.3;
elseif indexBiggest == 4      
    %Green
    colourSegmentationMask = ((HSVImage(:,:,1) > 70 & HSVImage(:,:,1) < 155) | HSVImage(:,:,1) == 70) & HSVImage(:,:,2) > 0.2 & HSVImage(:,:,3) > 0.3;
elseif indexBiggest == 5      
    %Cyan
    colourSegmentationMask = ((HSVImage(:,:,1) > 155 & HSVImage(:,:,1) < 205) | HSVImage(:,:,1) == 155) & HSVImage(:,:,2) > 0.2 & HSVImage(:,:,3) > 0.3;
elseif indexBiggest == 6      
    %Blue
    colourSegmentationMask = ((HSVImage(:,:,1) > 205 & HSVImage(:,:,1) < 260) | HSVImage(:,:,1) == 205) & HSVImage(:,:,2) > 0.2 & HSVImage(:,:,3) > 0.3;
elseif indexBiggest == 7      
    %Purple
    colourSegmentationMask = ((HSVImage(:,:,1) > 260 & HSVImage(:,:,1) < 315) | HSVImage(:,:,1) == 260) & HSVImage(:,:,2) > 0.2 & HSVImage(:,:,3) > 0.3;
elseif indexBiggest == 8      
    %White
    colourSegmentationMask = (HSVImage(:,:,3) > 0.6 | HSVImage(:,:,3) == 0.6) & (HSVImage(:,:,2) < 0.2 | HSVImage(:,:,2) == 0.2);
elseif indexBiggest == 9      
    %Black
    colourSegmentationMask = HSVImage(:,:,3) < 0.3 | HSVImage(:,:,3) == 0.3 | (HSVImage(:,:,3) < 0.6 & (HSVImage(:,:,2) < 0.2 | HSVImage(:,:,2) == 0.2));
else
    disp('error');
end

%Fill up the hole in the binary image.
maskFill =imfill(colourSegmentationMask,'holes');



SegmentationMask = bwselect(maskFill,centerOfObjectY,centerOfObjectX);


end

