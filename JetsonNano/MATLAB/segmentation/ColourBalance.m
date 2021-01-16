function [colourBalancedImage] = ColourBalance(originalImage)

%The function takes in a image and balances the colours. So that different
%lightnings will not have that big effect.

%Input:
%originalImage          - RGB image 984x740x3

%Output:
%colourBalancedImage    - RGB image 984x740x3

%Calculate number of pixales in te image
[imageHeight,imageWidth,~] = size(originalImage);

numPixel = imageHeight * imageWidth;

%Calculate the mean of every colour and take the mean of every colour added
%togheter
meanRed = sum(originalImage(:,:,1),'all')/numPixel;
meanGreen = sum(originalImage(:,:,2),'all')/numPixel;
meanBlue = sum(originalImage(:,:,3),'all')/numPixel;
meanTotal = (meanRed + meanGreen + meanBlue) / 3;

%Create a new image and use the mean value of the colours to calculate the
%new colours

oldRedLayer = originalImage(:,:,1);
oldGreenLayer = originalImage(:,:,2);
oldBlueLayer = originalImage(:,:,3);


newRedLayer = oldRedLayer * (meanTotal / meanRed);
newGreenLayer = oldGreenLayer * (meanTotal / meanGreen);
newBlueLayer = oldBlueLayer * (meanTotal / meanBlue);

colourBalancedImage = cat(3, newBlueLayer, newGreenLayer, newRedLayer);



end

