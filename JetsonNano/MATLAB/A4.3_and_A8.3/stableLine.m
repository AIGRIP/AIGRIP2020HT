function [targetPointF1Y,targetPointF1X, normalPointF1Y,normalPointF1X, ... 
    targetPointF2Y, targetPointF2X, normalPointF2Y,normalPointF2X, ... 
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
    normalXconst = 50;

    totalNumberOfDegrees = length( degreesMeasured );
    
    % Resolution of possible grip positions.
    resolutionGrasp = 10;
    
    indexOffset = round( (resolutionGrasp/2)*(totalNumberOfDegrees/360) );
    
    % Angle points for grasping on finger 1.
    anglePointsF1 = 95:resolutionGrasp:175;
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
    targetPointF1X,normalPointF1Y,normalPointF1X,1);
    
    % Angle points for grasping on finger 2.
    anglePointsF2 = 185:resolutionGrasp:265;
    % Indexes of angular points for finger 2.
    indexToMeasureFinger2 = round( anglePointsF2*totalNumberOfDegrees/360 );
    
    % Signature for finger 1.
    signatureRadiusTargetF2 = signatureRadius(indexToMeasureFinger2);
    
    % Allocate memory for normal points.
    normalPointF2X = zeros(indexOffset*2+1,1);
    normalPointF2Y = zeros(indexOffset*2+1,1);
    
    % Allocate memory for normal points.
    targetPointF2X = XCoordinates( indexToMeasureFinger2 );
    targetPointF2Y = YCoordinates( indexToMeasureFinger2 );
    
    for ii=1:length(indexToMeasureFinger2)
    
        % Get the index of points to measure surface.
        indexBuffer = (indexToMeasureFinger2(ii)-indexOffset) : (indexToMeasureFinger2(ii)+indexOffset);
        
        % Calculate polynom coefficients.
        polynomCoefficients = polyfit(XCoordinates(indexBuffer),YCoordinates(indexBuffer),1);
        
        % Calculate the normal of a first degree polynom.
        normalCoefficient = -1/polynomCoefficients(1);
        
        % To set the normal point withi the object.
        if(normalCoefficient < 0 )
            normalPointF2Y(ii) = normalXconst*normalCoefficient+YCoordinates( indexToMeasureFinger2(ii) );
            normalPointF2X(ii) = normalXconst+XCoordinates( indexToMeasureFinger2(ii) );
        else
            normalPointF2Y(ii) = -normalXconst*normalCoefficient+YCoordinates( indexToMeasureFinger2(ii) );
            normalPointF2X(ii) = -normalXconst+XCoordinates( indexToMeasureFinger2(ii) );
        end 
    end
    
    % Signature for finger 1.
    signatureRadiusTargetF1 = signatureRadius(indexToMeasureFinger1);
    
    % Set the priority order of the target points.
    [targetPointF2Y,targetPointF2X,normalPointF2Y,normalPointF2X] = ...
    priorityOfGripPoints(signatureRadiusTargetF2,targetPointF2Y, ...
    targetPointF2X,normalPointF2Y,normalPointF2X,2);
    
end

