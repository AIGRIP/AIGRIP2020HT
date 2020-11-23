function [targetPointY,targetPointX,normalPointY,normalPointX] = ...
    priorityOfGripPoints(signatureRadius,targetPointY, ...
    targetPointX,normalPointY,normalPointX)
%priorityOfGripPoints makes a priority of sugested points based on
%signature. The suggested target with lowest radius get highest priority.

    [~,minRadiusIndex] = sort(signatureRadius);

    targetPointY = targetPointY(minRadiusIndex);
    targetPointX = targetPointX(minRadiusIndex);
    normalPointY = normalPointY(minRadiusIndex);
    normalPointX = normalPointX(minRadiusIndex);
    
end

