function [targetPointY,targetPointX,normalPointY,normalPointX] = ...
    PriorityOfGripPoints(signatureRadius,targetPointY, ...
    targetPointX,normalPointY,normalPointX)
%priorityOfGripPoints makes a priority of sugested points based on
%signature. The suggested target with lowest radius get highest priority.

    % Set priority based on signature.
    [~,minRadiusIndex] = sort(signatureRadius);

    % Sort the target points in the priority order.
    targetPointY = targetPointY(minRadiusIndex);
    targetPointX = targetPointX(minRadiusIndex);
    normalPointY = normalPointY(minRadiusIndex);
    normalPointX = normalPointX(minRadiusIndex);
    
end

