function [targetPointF1Y,targetPointF1X, normalPointF1Y,normalPointF1X, ... 
    targetPointF2Y, targetPointF2X, normalPointF2Y,normalPointF2X,targetPointF0Y,targetPointF0X,normalPointF0Y,normalPointF0X, ... 
    signatureRadiusTargetF1,signatureRadiusTargetF2] = ...
    stableLine(degreesMeasured,YCoordinates,XCoordinates,signatureRadius)
%stableLine finds the required orientaions for the gripper to grasp an object.
%   degreesMeasured - Containes the angles for each measurement point.
%   YCoordinates    - Containes the cartesean Y-coordinate for each angle.
%                   It has the same indexes as degreesMeasured.
%   XCoordinates    - Containes the cartesean X-coordinate for each angle.
%                   It has the same indexes as degreesMeasured.
%   targetPoint     - Returns the position of the all target points. The
%                   number after letter F indicates which finger the target
%                   points belong to. X and Y indicate which coordinate
%                   vector it is.
%   normalPoint     - Returns a normal point for each of the target points. The
%                   number after letter F indicates which finger the target
%                   points belong to. X and Y indicate which coordinate
%                   vector it is.
%   signatureRadiusTargetF - Is the signature for finger 1 and 2.
    
    %Offset in x-direction for the normal points.
    normalXconst = 50;
    
    % Resolution of possible grip positions in degrees.
    resolutionGrasp = 5;
    
    % Defines the workspace in angles from the center of the gripper for
    % of each finger. The first finger has the workspace in angles:
    % "90 - atand(36/(23+38+(60*cosd(60))-11))" to "180-atand(23/(36+38+(60*cosd(60))-11))"
    % And the second finger.
    % "90 - atand(36/(23+38+(60*cosd(60))-11))" to "180-atand(23/(36+38+(60*cosd(60))-11))"
    % The finger 0 (thumb) only has one direction.

    anglePointsF1 = 115:resolutionGrasp:166;
    anglePointsF2 = 205:resolutionGrasp:256;

    totalNumberOfDegrees = length( degreesMeasured );
    
    % The number of neighbours used to get the polynomal.
    indexOffset = round( (resolutionGrasp/2)*(totalNumberOfDegrees/360) );
    
    % Indexes of angular points for finger 1.
    indexToMeasureFinger1 = round( anglePointsF1*totalNumberOfDegrees/360 );
    
    % Allocate memory to select samples.
    indexBuffer = zeros(indexOffset*2+1,1);
    % Allocate memory for normal points.
    normalPointF1X = zeros(indexOffset*2+1,1);
    normalPointF1Y = zeros(indexOffset*2+1,1);
    
    % Allocate memory for normal points.
    targetPointF1X = XCoordinates( indexToMeasureFinger1 );
    targetPointF1Y = YCoordinates( indexToMeasureFinger1 );

    % Calculates the normal for all target points for finger 1.
    for ii=1:length(indexToMeasureFinger1)
    
        % Get the index of points to measure surface.
        indexBuffer = (indexToMeasureFinger1(ii)-indexOffset) : (indexToMeasureFinger1(ii)+indexOffset);
        
        % Calculate polynom coefficients.
        polynomCoefficients = polyfit(XCoordinates(indexBuffer),YCoordinates(indexBuffer),1);
        
        % Calculate the normal of a first degree polynom.
        normalCoefficient = -1/polynomCoefficients(1);
        
        % To set the normal point withi the object.
        if(normalCoefficient < 0 )
            normalPointF1Y(ii) = normalXconst*normalCoefficient+YCoordinates( indexToMeasureFinger1(ii) );
            normalPointF1X(ii) = normalXconst+XCoordinates( indexToMeasureFinger1(ii) );
        else
            normalPointF1Y(ii) = -normalXconst*normalCoefficient+YCoordinates( indexToMeasureFinger1(ii) );
            normalPointF1X(ii) = -normalXconst+XCoordinates( indexToMeasureFinger1(ii) );
        end

    end
    
    % Signature for finger 1.
    signatureRadiusTargetF1 = signatureRadius(indexToMeasureFinger1);
    
    % Set the priority order of the target points.
    [targetPointF1Y,targetPointF1X,normalPointF1Y,normalPointF1X] = ...
    priorityOfGripPoints(signatureRadiusTargetF1,targetPointF1Y, ...
    targetPointF1X,normalPointF1Y,normalPointF1X);
    
    % Indexes of angular points for finger 2.
    indexToMeasureFinger2 = round( anglePointsF2*totalNumberOfDegrees/360 );
    
    % Allocate memory for normal points.
    normalPointF2X = zeros(indexOffset*2+1,1);
    normalPointF2Y = zeros(indexOffset*2+1,1);
    
    % Allocate memory for normal points.
    targetPointF2X = XCoordinates( indexToMeasureFinger2 );
    targetPointF2Y = YCoordinates( indexToMeasureFinger2 );
    
    % Calculates the normal for all target points for finger 1.
    for ii=1:length(indexToMeasureFinger2)
    
        % Get the index of points to measure surface.
        indexBuffer = (indexToMeasureFinger2(ii)-indexOffset) : (indexToMeasureFinger2(ii)+indexOffset);
        
        % Calculate polynom coefficients.
        polynomCoefficients = polyfit(XCoordinates(indexBuffer),YCoordinates(indexBuffer),1);
        
        % Calculate the normal of a first degree polynom.
        normalCoefficient = -1/polynomCoefficients(1);
        
        % To set the normal point withi the object.
        if(normalCoefficient < 0 )
            normalPointF2Y(ii) = -normalXconst*normalCoefficient+YCoordinates( indexToMeasureFinger2(ii) );
            normalPointF2X(ii) = -normalXconst+XCoordinates( indexToMeasureFinger2(ii) );
        else
            normalPointF2Y(ii) = normalXconst*normalCoefficient+YCoordinates( indexToMeasureFinger2(ii) );
            normalPointF2X(ii) = normalXconst+XCoordinates( indexToMeasureFinger2(ii) );
        end 
    end
    
    % Signature for finger 2.
    signatureRadiusTargetF2 = signatureRadius(indexToMeasureFinger2);
    
    % Set the priority order of the target points.
    [targetPointF2Y,targetPointF2X,normalPointF2Y,normalPointF2X] = ...
    priorityOfGripPoints(signatureRadiusTargetF2,targetPointF2Y, ...
    targetPointF2X,normalPointF2Y,normalPointF2X);


    % Get normal for finger 0.
    
    indexToCheckF0 = [1:indexOffset,indexOffset:length(XCoordinates)];
    
    % Calculate polynom coefficients.
    polynomCoefficients = polyfit(XCoordinates(indexToCheckF0),YCoordinates(indexToCheckF0),1);

    % Calculate the normal of a first degree polynom.
    normalCoefficient = -1/polynomCoefficients(1);
    
    normalPointF0Y = -normalXconst*normalCoefficient+YCoordinates( indexToMeasureFinger2(ii) );
    normalPointF0X = -normalXconst+XCoordinates( indexToMeasureFinger2(ii) );
    
    targetPointF0X = XCoordinates(1);
    targetPointF0Y = YCoordinates(1);
    
end

