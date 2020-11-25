function [lengthPixel, realObjectWidth] = GetPixelLength(binaryImage, objectMidPoint, distanceToObject )

    %This function will calculate the width of an object in an image taken
    %by a raspberry 

    %Input:
    %binaryImage = An binary image where an object have been segmentated

    %objectMidPoint = A rough estimation of the objects midpoint. midpoint
    %is calculated with pixels in the image
    
    %distanceToObject = distance to object in mm.
    
    %Output:
    %lengthPixel = What one pixel equals for distance in the real world.


% Set the standard vaiabels for the camera
focalLength  = 3.01;
sensorWidth = 3.68;
sensorWidthPixels = 740 ;
%Calculate the width of the object in pixels
objectWidthPixels = sum(binaryImage(objectMidPoint,:))
%Calculate the width of the object on the sensor in mm
objectWidthOnSensor = sensorWidth * objectWidthPixels / sensorWidthPixels;
%Calculate the width of the object in the real world
realObjectWidth = distanceToObject * objectWidthOnSensor / focalLength;
%Calculate what length one pixel corresponds to in the real world
lengthPixel = realObjectWidth / objectWidthPixels; 

end

