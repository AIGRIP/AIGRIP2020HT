function [edgePointsmm] = GetPixelLength( centerPointPixel  ,edgePointsPixel ,distanceToObject )

    %This function will calculate the length of one pixel of an object.
    %Then convert pixel positions into real world coordinates in mm.
    
    %Input:
    %centerPointPixel   - Center of the pixel area. x and y postion. 
    %                       Position is in pixels
    %edgePointsPixel    - Points along the edge of the pixel area. array with 
    %                       x and y postion. Positions is in pixels
    %distanceToObject   - distance to object in mm.
    
    %Output:
    %edgePointsmm       - edgePointsPixel converted to mm

    % Focal length in pixels
    focalLengthPixel = 736;
    %Calculate the width of the object in pixels
    lengthPixel = distanceToObject * (1 / focalLengthPixel);
    %Convert the points from pixels to mm
    edgePointsmm = (edgePointsPixel-centerPointPixel)*lengthPixel;

end

