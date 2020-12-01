function [signature,YCoordToStore,XCoordToStore] = ...
    GetSignature(binaryEdgeImage,degreesToMeasure,numberOfRows,numberOfColumns)
%GetSignature caclulates the radius dependent on the angle.
%   binaryEdgeImage     - Should be a binary édge image.
%   degreesToMeasure    - Is the degrees in radian that should store the
%                       pixel values and use it to find grip positions.
%   rowsOfImage         - Is the number rows of the image.
%   columnsOfImage      - Is the number columns of the image.
%   signature           - Returns the radius for each of the defined angle.
%   YCoordToStore       - Is the cartesean Y-cordinates of the signature.
%   XCoordToStore       - Is the cartesean X-cordinates of the signature.
    
    % Focus point is set to the middle of the image.
    rowFocusSignature = round(numberOfRows/2);
    columnFocusSignature = round(numberOfColumns/2);

    % Get index of all high pixels.
    edgePointsIndex = find(binaryEdgeImage == 1);
    
    % Get x and y cordinates.
    yPCoord = floor( edgePointsIndex/numberOfRows );
    xPCoord = mod( edgePointsIndex, numberOfRows );

    % Get the offset from the center of the image.
    dY = columnFocusSignature - yPCoord;
    dX = rowFocusSignature - xPCoord;

    % Convert the coordinates from the centroid to angular degree from
    % 0 to 2pi
    angCP = YXtoAngle(dY,dX);

    % Get the signature with the right number of feature (Radius,Angle).
    [signature,YCoordToStore,XCoordToStore] = GetARsing(angCP,dY,dX,degreesToMeasure);


end

