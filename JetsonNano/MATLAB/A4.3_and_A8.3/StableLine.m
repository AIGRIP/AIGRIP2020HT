function [targetPointF1Y,targetPointF1X, normalPointF1Y,normalPointF1X, ... 
    targetPointF2Y, targetPointF2X, normalPointF2Y,normalPointF2X,targetPointF0Y,targetPointF0X,normalPointF0Y,normalPointF0X, ... 
    signatureRadiusTargetF1,signatureRadiusTargetF2] = ...
    StableLine(degreesMeasured,YCoordinates,XCoordinates,signatureRadius)
%stableLine finds the required orientaions for the gripper to grasp an
%object. And set priority of the gripper points based on the signature. It
%calcculate target point and normal for all of the fingers.
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
    
    %Offset in radius for the normal points.
    normalRadius = 50;
    
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
    
    uniquePoints = unique([XCoordinates,YCoordinates],'rows');
    
    % Indexes of angular points for finger 1.
    indexToMeasureFinger1 = round( anglePointsF1*totalNumberOfDegrees/360 );
    
    % Size of index buffer.
    indexBufferSize = indexOffset*2+1;
    % Allocate memory to select samples.
    indexBuffer = zeros(indexBufferSize,1);
    % Allocate memory for normal points.
    normalPointF1X = zeros(length(indexToMeasureFinger1),1);
    normalPointF1Y = zeros(length(indexToMeasureFinger1),1);
    
    % Allocate memory for normal points.
    targetPointF1X = XCoordinates( indexToMeasureFinger1 );
    targetPointF1Y = YCoordinates( indexToMeasureFinger1 );
    
    % Calculates the normal for all target points for finger 1.
    for ii=1:length(indexToMeasureFinger1)
    
        % Calculates the euclodian distance to target.
        distanceToTargetX = uniquePoints(:,1) - targetPointF1X(ii);
        distanceToTargetY = uniquePoints(:,2) - targetPointF1Y(ii);
        
        % Get the closest unique indecies to the target point.
        [~,indexBuffer] = mink( sum( distanceToTargetX.^2 + distanceToTargetY.^2,2),indexBufferSize);
        
        % Get the length vectors to neighbour
        xDirection = targetPointF1X(ii)-uniquePoints(indexBuffer(indexBufferSize),1);
        yDirection = targetPointF1Y(ii)-uniquePoints(indexBuffer(indexBufferSize),2);
        % Get the angle from target to neighbour.
        angleDirection = atan(yDirection/xDirection);
        % Get the normal point to the target point.
        normalPointF1X(ii) = targetPointF1X(ii) + normalRadius*cos(angleDirection+pi/2);
        normalPointF1Y(ii) = targetPointF1Y(ii) + normalRadius*sin(angleDirection+pi/2);

    end
    
    % Signature for finger 1.
    signatureRadiusTargetF1 = signatureRadius(indexToMeasureFinger1);
    
    % Set the priority order of the target points.
    [targetPointF1Y,targetPointF1X,normalPointF1Y,normalPointF1X] = ...
    PriorityOfGripPoints(signatureRadiusTargetF1,targetPointF1Y, ...
    targetPointF1X,normalPointF1Y,normalPointF1X);
    
    % Indexes of angular points for finger 2.
    indexToMeasureFinger2 = round( anglePointsF2*totalNumberOfDegrees/360 );
    
    % Allocate memory for normal points.
    normalPointF2X = zeros(length(indexToMeasureFinger2),1);
    normalPointF2Y = zeros(length(indexToMeasureFinger2),1);
    
    % Allocate memory for normal points.
    targetPointF2X = XCoordinates( indexToMeasureFinger2 );
    targetPointF2Y = YCoordinates( indexToMeasureFinger2 );
    
    % Calculates the normal for all target points for finger 1.
    for ii=1:length(indexToMeasureFinger2)

        % Calculates the euclodian distance to target.
        distanceToTargetX = uniquePoints(:,1) - targetPointF2X(ii);
        distanceToTargetY = uniquePoints(:,2) - targetPointF2Y(ii);
        
        % Get the closest unique indecies to the target point.
        [~,indexBuffer] = mink( sum( distanceToTargetX.^2 + distanceToTargetY.^2,2),indexBufferSize);
        
        % Get the length vectors to neighbour
        xDirection = targetPointF2X(ii)-uniquePoints(indexBuffer(indexBufferSize),1);
        yDirection = targetPointF2Y(ii)-uniquePoints(indexBuffer(indexBufferSize),2);
        
        % Get the angle from target to neighbour.
        angleDirection = atan(yDirection/xDirection);
        
        % Get the normal point to the target point.
        normalPointF2X(ii) = targetPointF2X(ii) + normalRadius*cos(angleDirection+pi/2);
        normalPointF2Y(ii) = targetPointF2Y(ii) + normalRadius*sin(angleDirection+pi/2);
    end
    
    % Signature for finger 2.
    signatureRadiusTargetF2 = signatureRadius(indexToMeasureFinger2);
    
    % Set the priority order of the target points.
    [targetPointF2Y,targetPointF2X,normalPointF2Y,normalPointF2X] = ...
    PriorityOfGripPoints(signatureRadiusTargetF2,targetPointF2Y, ...
    targetPointF2X,normalPointF2Y,normalPointF2X);


    % Get normal for finger 0.
    
    targetPointF0X = XCoordinates(1);
    targetPointF0Y = YCoordinates(1);
    
    % Calculates the euclodian distance to target.
    distanceToTargetF0X = uniquePoints(:,1) - targetPointF0X;
    distanceToTargetF0Y = uniquePoints(:,2) - targetPointF0Y;
    
    % Get the closest unique indecies to the target point.
    [~,indexBuffer] = mink( sum( distanceToTargetF0X.^2 + distanceToTargetF0Y.^2,2),indexBufferSize);

    % Get the length vectors to neighbour
    xDirection = targetPointF0X-uniquePoints(indexBuffer(indexBufferSize),1);
    yDirection = targetPointF0Y-uniquePoints(indexBuffer(indexBufferSize),2);

    % Get the angle from target to neighbour.
    angleDirection = atan(yDirection/xDirection);

    % Get the normal point to the target point.
    normalPointF0X = targetPointF0X + normalRadius*cos(angleDirection+pi/2);
    normalPointF0Y = targetPointF0Y + normalRadius*sin(angleDirection+pi/2);
    
end

