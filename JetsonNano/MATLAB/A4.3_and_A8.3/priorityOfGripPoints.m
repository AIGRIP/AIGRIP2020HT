function [targetPointY,targetPointX,normalPointY,normalPointX,validPositions] = ...
    priorityOfGripPoints(signatureRadius,targetPointY, ...
    targetPointX,normalPointY,normalPointX,fingerNumber)
%priorityOfGripPoints makes a priority of sugested points based on
%signature. The suggested target with lowest radius get highest priority.


    % Check if target points is reachable for grippers pre-shape.

    % Offset from center to signularity point of finger.
    XdistanceTosingularity = -20;
    if(fingerNumber == 1)
        YdistanceTosingularity = 36;
    else
        YdistanceTosingularity = -36;
    end

    % Set priority based on signature.
    [~,minRadiusIndex] = sort(signatureRadius);

%     % Maximum radius of finger during parallell grasp. Offset from
%     % singularity point is 30 mm. The link C is 60 mm and the distance
%     % between the joint and finger nail surface is 10 mm.
%     maxRadiusParallellGrasp = 30+(60*cos(50))-10;
% 
%     % Get distance from singularity point to finger surface.
%     distanceTargetPointToSignularityPoint = ...
%         sqrt((targetPointX + XdistanceTosingularity).^2 + (targetPointY + YdistanceTosingularity).^2);
%     
%     % Get the indexes that is reachable.
%     reachableIndex = (distanceTargetPointToSignularityPoint < maxRadiusParallellGrasp);
%     
%     % Get the amount of valid positions.
%     validPositions = sum(reachableIndex);
%     
%     % Update the priority based on reachable configurations.
%     minRadiusIndex(1:validPositions) = minRadiusIndex(reachableIndex);
    
    % Sort the target points in the priority order.
    targetPointY = targetPointY(minRadiusIndex);
    targetPointX = targetPointX(minRadiusIndex);
    normalPointY = normalPointY(minRadiusIndex);
    normalPointX = normalPointX(minRadiusIndex);
    
end

