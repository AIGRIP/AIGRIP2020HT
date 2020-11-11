function [motorAngles] = inverseKinematicsPreshape(desiredPosition,normStableLine)

    

linkLengtha = 25;
linkLengthb = 95;
linkLengthc = 60;
linkLengthd = 35;

motorPositionM1 = [60,60]; %Calculate actaul position
motorPositionM2 = motorPositionM1 + [29 -38];

directionPosition = normStableLine - motorPositionM1;

if directionPosition == 0
    directionPosition = normStableLine + desiredPosition - motorPositionM1;
end

motorAngles(1) = angle(directionPosition(1) + directionPosition(2)*1i);



if  motorAngles(1) > (pi/2)
    motorAngles(1) = motorAngles(1) - pi;
elseif motorAngles(1) < -(pi/2)
    motorAngles(1) = motorAngles(1) + pi;
end


distanceX = desiredPosition(1) - motorPositionM1(1);
distanceY = desiredPosition(2) - motorPositionM1(2);

distance = sqrt( distanceX^2 + distanceY^2 );

motorAngles(2) = pi/2 - acos(distance / linkLengthc);
if distanceX >= 0 && distanceY >= 0
    motorAngles(2) = -motorAngles(2);
end

motorAngles(2) = 0.3491;

motorAngles(3) = parallelMotorAnglet2(motorAngles(2),motorPositionM1,motorPositionM2,linkLengtha,linkLengthb,linkLengthc,linkLengthd);

motorAngles = rad2deg(motorAngles);

end