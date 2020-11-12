function [motorAngles] = inverseKinematicsPreshape(desiredPosition,normStableLine)




%Set length values for all links in model
linkLengtha = 25;
linkLengthb = 95;
linkLengthc = 60;
linkLengthd = 35;

%Set the posistion of motor M0 relative to the center of the palm
motorPositionM3 = [0,0];
%Make the direction relate to M0 position instead of palm center
directionPosition = normStableLine - motorPositionM3;
%If the directionPosition is the same as motorPositionM0 move the direction
%in the normal direction
if directionPosition == 0
    directionPosition = normStableLine + desiredPosition - motorPositionM3;
end
%Calcualet the angle that motor M0 should move to
motorAngles(1) = angle(directionPosition(1) + directionPosition(2)*1i);

%Change the angles to be between 0-90 degree
if motorAngles(1) < -(pi/2)
    motorAngles(1) = motorAngles(1) + pi;
elseif  motorAngles(1) > (pi/2)
    motorAngles(1) = motorAngles(1) - pi;
end
motorAngles(1) = abs(motorAngles(1));

%Calculate the distance from the palm center to the poistions 
%of motor M1 and M2
motorPositionM1 = [60,60]; %Calculate actaul position
motorPositionM2 = motorPositionM1 + [29 -38];

%Calculate the distance from motor M1 to the desired position 
distanceX = desiredPosition(1) - motorPositionM1(1);
distanceY = desiredPosition(2) - motorPositionM1(2);
distance = sqrt( distanceX^2 + distanceY^2 );

motorAngles(2) = pi/2 - acos(distance / linkLengthc);
if distanceX >= 0 && distanceY >= 0
    motorAngles(2) = -motorAngles(2);
end

motorAngles(3) = parallelMotorAnglet2(motorAngles(2),motorPositionM1,motorPositionM2,linkLengtha,linkLengthb,linkLengthc,linkLengthd);

motorAngles = int16(rad2deg(motorAngles) * 65535 / 359);



end