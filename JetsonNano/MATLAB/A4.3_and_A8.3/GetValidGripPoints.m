function [motorSteps, bestTargetPointY, bestTargetPointX,bestNormalPointY,bestNormalPointX] = ...
GetValidGripPoints(targetPointYPixel,targetPointXPixel,normalPointYPixel,normalPointXPixel,distanceToObject,fingerNumber)
%getValidGripPoints checks if the target points is possible for the gripper
%to grasp correctly. Consider to the mouse sensor and the workspace of the
%gripper. It return motor values for the current finger and the best target
%point and its normal.
%   targetPointYPixel   - Is the desired point for the gripper to grasp in
%   y direction.
%   targetPointXPixel   - Is the desired point for the gripper to grasp in
%   x direction.
%   normalPointYPixel   - Is the y-coordinate normal point to the surface.
%   normalPointXPixel   - Is the x-coordinate normal point to the surface.
%   distanceToObject    - Is the current distance to the object.
%   fingerNumber        - Is the finger of the gripper. Finger 0 is the
%                           thumb. Finger 1 is the "first finger". Finger 2
%                           is the "long finger".
%   motorSteps          - Returns the position for the motors.
%   bestTargetPointY    - Returns the best point in Y-direction.
%   bestTargetPointX    - Returns the best point in X-direction.
%   bestNormalPointY    - Returns the normal of best point in Y-direction.
%   bestNormalPointX    - Returns the normal of best point in X-direction.

    % Define the links of the gripper fingers.
    linkLengtha = 25;
    linkLengthb = 95;
    linkLengthc = 60;
    linkLengthd = 35;
    linkLengthe = 50;

    linkLengths = [linkLengtha, linkLengthb, linkLengthc, linkLengthd, linkLengthe];

    
    % Convert to pixelcoordinates to real cordinates. 
    % "Real coordinate X" = "-1*Pixel Coordinate Y"
    % "Real coordinate Y" = "Pixel Coordinate X"
    targetPointX = -1*GetPixelLength( 0 ,targetPointYPixel ,distanceToObject );
    targetPointY = GetPixelLength( 0 ,targetPointXPixel ,distanceToObject );
    normalPointX = -1*GetPixelLength( 0 ,normalPointYPixel ,distanceToObject );
    normalPointY = GetPixelLength( 0 ,normalPointXPixel ,distanceToObject );

    % Check if target points is reachable for grippers pre-shape.

    % Offset from center to signularity point of finger.
    XdistanceTosingularity = -23;
    
    % Set the default value dependent on which finger and check if finger
    % is in workspace.
    if(fingerNumber == 1)
        % Singularity point Y coordinate for finger 1.
        YdistanceTosingularity = 36;
        
        % Check if finger 1 is within its workspace.
        pointsInRightQuadrant = ((targetPointX <= XdistanceTosingularity) & (targetPointY >= YdistanceTosingularity)) ...
            | ((targetPointX >= XdistanceTosingularity) & (targetPointY <= YdistanceTosingularity));
        
        
        % Set motor to default poistion if there is no valid target point.
        % For finger 1.
        bestTargetPointY = YdistanceTosingularity;
        bestTargetPointX = XdistanceTosingularity-55;
        bestNormalPointY = YdistanceTosingularity;
        bestNormalPointX = XdistanceTosingularity;
    elseif(fingerNumber == 2)
        % Singularity point Y coordinate for finger 2.
        YdistanceTosingularity = -36;
        
        % Check if finger 2 is within its workspace.
        pointsInRightQuadrant = ((targetPointX >= XdistanceTosingularity) & (targetPointY >= YdistanceTosingularity)) ...
            | ((targetPointX <= XdistanceTosingularity) & (targetPointY <= YdistanceTosingularity));
        
        % Set motor to default poistion if there is no valid target point.
        % For finger 2.
        bestTargetPointY = YdistanceTosingularity;
        bestTargetPointX = XdistanceTosingularity-55;
        bestNormalPointY = YdistanceTosingularity;
        bestNormalPointX = 0;
    else
        
        % Check if the target point is reachable.
        if ( ( (64 -(60*cosd(34)+11)) < targetPointX(1) ) && (targetPointX(1) < ( 64 +(60*cosd(60)-11)) ) )
        
            % Check if the angle between surface and finger surface. If it
            % is less then 60 degrees it is a valid point to grasp with
            % finger 0.
            if atand(abs(normalPointY(1))/abs(targetPointX(1)-normalPointX(1))) < 60

                motorSteps = InverseKinematicsPreshape(linkLengths, ... 
                    [targetPointX(1),0], [normalPointX(1),normalPointY(1)], fingerNumber);
                % Return the coordinate for the finger 0 to grip.
                bestTargetPointY = targetPointY(1);
                bestTargetPointX = targetPointX(1);
                bestNormalPointY = normalPointY(1);
                bestNormalPointX = normalPointX(1);
                return
            end
        end
        
        % Set motor to default poistion if there is no valid target point.
        % For finger 2.
        bestTargetPointY = 0;
        bestTargetPointX = 64+(60*cosd(60))-11;
        bestNormalPointY = 0;
        bestNormalPointX = 0;
        % If there was no valid target point.
        motorSteps = InverseKinematicsPreshape(linkLengths, ... 
            [bestTargetPointX,bestTargetPointY], [bestNormalPointX,bestNormalPointY], fingerNumber);
        return
    end
    

    % Maximum radius of finger during parallell grasp. Offset from
    % singularity point is 38 mm. The link C is 60 mm and the distance
    % between the joint and finger nail surface is 11 mm.
    maxRadiusParallellGrasp = abs( 38+(60*cosd(60))-11 );
    minRadiusParallellGrasp = abs( (60*cosd(34))+11-38 );

    % Get distance from singularity point to finger surface.
    distanceTargetPointToSignularityPoint = ...
        sqrt((targetPointX - XdistanceTosingularity).^2 + (targetPointY - YdistanceTosingularity).^2);
    
    % Allocate space to indicate point within range.
    pointsInRightRange = zeros(length(targetPointX),1);
    
    % Get the indexes that is within the range.
    for i=1:length(targetPointX)
        % Check witch side of the singluaraity the point is in.
        if targetPointX(i) > XdistanceTosingularity
            pointsInRightRange(i) = (distanceTargetPointToSignularityPoint(i) < minRadiusParallellGrasp);
        else
            pointsInRightRange(i) = (distanceTargetPointToSignularityPoint(i) < maxRadiusParallellGrasp);
        end
    end
    
    % Get the indexes that is reachable.
    reachableIndex = pointsInRightQuadrant & pointsInRightRange;
    
    % Get the amount of valid positions.
    nrValidPoints = sum(reachableIndex);
    
    % Set the valid gripping point in priority order.
    targetPointY(1:nrValidPoints) = targetPointY(reachableIndex);
    targetPointX(1:nrValidPoints) = targetPointX(reachableIndex);
    normalPointY(1:nrValidPoints) = normalPointY(reachableIndex);
    normalPointX(1:nrValidPoints) = normalPointX(reachableIndex);
    

    if 0 < nrValidPoints
        for i=1:nrValidPoints
            % Check if the orientation is possible.
            if PointToLine([XdistanceTosingularity,YdistanceTosingularity], ...
                [targetPointX(i),targetPointY(i)],[normalPointX(i),normalPointY(i)]) == 1

                % Set the return value.
                bestTargetPointY = targetPointY(i);
                bestTargetPointX = targetPointX(i);
                bestNormalPointY = normalPointY(i);
                bestNormalPointX = normalPointX(i);
                break;
            end
        end
    end

    % Return the motor steps for the current.
    motorSteps = InverseKinematicsPreshape(linkLengths, ... 
        [bestTargetPointX,bestTargetPointY], [bestNormalPointX,bestNormalPointY], fingerNumber);
end

