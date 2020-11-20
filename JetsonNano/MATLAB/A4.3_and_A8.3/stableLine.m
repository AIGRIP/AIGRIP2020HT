function [targetPointF1Y,targetPointF1X, normalPointY,normalPointX] = stableLine(degreesMeasured,YCoordinates,XCoordinates)
%stableLine finds the required orientaions for the gripper to grasp an object.
%   degreesMeasured - Containes the angles for each measurement point.
%   YCoordinates    - Containes the cartesean Y-coordinate for each angle.
%                   It has the same indexes as degreesMeasured.
%   XCoordinates    - Containes the cartesean X-coordinate for each angle.
%                   It has the same indexes as degreesMeasured.

    totalNumberOfDegrees = length( degreesMeasured );
    
    % Resolution of possible grip positions.
    resolutionGrasp = 10;
    
    indexOffset = round( (resolutionGrasp/2)*(totalNumberOfDegrees/360) );
    
    % Angle points for grasping on finger 1.
    indexToMeasureFinger1 = round( (95:resolutionGrasp:175)*totalNumberOfDegrees/360 );

    % Angle points for grasping on finger 2.
    indexToMeasureFinger2 = round( (185:resolutionGrasp:265)*totalNumberOfDegrees/360 );
    
    % Allocate memory to select samples.
    indexBuffer = zeros(indexOffset*2+1,1);
    % Allocate memory for normal points.
    normalPointX = zeros(indexOffset*2+1,1);
    normalPointY = zeros(indexOffset*2+1,1);
    
    targetPointF1X = XCoordinates( indexToMeasureFinger1 );
    targetPointF1Y = YCoordinates( indexToMeasureFinger1 );

    for ii=1:length(indexToMeasureFinger1)
    
        % Get the index of points to measure surface.
        indexBuffer = (indexToMeasureFinger1(ii)-indexOffset) : (indexToMeasureFinger1(ii)+indexOffset);
        
        % Calculate polynom coefficients.
        polynomCoefficients = polyfit(XCoordinates(indexBuffer),YCoordinates(indexBuffer),1);
        
        % Calculate the normal of a first degree polynom.
        normalCoefficient = -1/polynomCoefficients(1);
        
        if(YCoordinates( indexToMeasureFinger1(ii) ) < 0 )
            normalPointY(ii) = normalCoefficient*YCoordinates( indexToMeasureFinger1(ii) );
        else
            normalPointY(ii) = -normalCoefficient*YCoordinates( indexToMeasureFinger1(ii) );
        end
        normalPointX(ii) = XCoordinates( indexToMeasureFinger1(ii) )+1;
        
    end
    
end

