function [motorAngles] = inverseKinematicsPreshape(desiredPosition,desiredAngle)

    
linkLengthc = 60;
motorPositionM1 = [0,0]; %Change this

distance = sqrt( (motorPositionM1(1)-desiredPosition(1))^2 + (motorPositionM1(2)-desiredPosition(2))^2 );

motorAngles = distance;
end