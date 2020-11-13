function [motorAngles] = inverseKinematicsPreshape(linkLengths, desiredPosition, normalStableLine)

    %This function calculates how every motor in a finger should be rotated for
    %it to reach a certain point with a certain angle and with the last link
    %being parallel to the palm of the gripper

    %Input:
    %linkLengths = 1x5 array with the lengths of all five links in the order
    %a,b,c,d,e

    %desiredPosition =  1x2 array with the x and y coordinates of the point
    %that the gripper should reach. The coordinates are relative to the palm
    %center

    %normalStableLine = 1x2 array with the x and y coordinates that together
    %with the desiredPosition creates the line which represents the normal. 
    %The coordinates are relative to the palm center

    %Output:
    %motorAngles = 1X3 array with three motor angles one for each motro in a
    %finger. The order of the motors in the array is M0,M1,M2. The angles are
    %remaped from 0-359 to 0-65535 this is to fill out a short as much as
    %possible.


    %Set the posistion of motor M0 relative to the center of the palm
    motorPositionM0 = [0,0];
    lengthM0toM1 = 9;
    %Make the direction relate to M0 position instead of palm center
    directionPosition = normalStableLine - motorPositionM0;
    %If the directionPosition is the same as motorPositionM0 move the direction
    %in the normal direction
    if directionPosition == 0
        directionPosition = normalStableLine + desiredPosition - motorPositionM0;
    end
    %Calcualet the angle that motor M0 should move to
    motorAngles(1) = angle(directionPosition(1) + directionPosition(2)*1i);

    %Change the angles to be between 0-90 degree
    if motorAngles(1) < -(pi/2)
        motorAngles(1) = motorAngles(1) + pi;
    elseif  motorAngles(1) > (pi/2)
        motorAngles(1) = motorAngles(1) - pi;
    end

    %Calculate the distance from the palm center to the poistions 
    %of motor M1 and M2
    motorPositionM1 = motorPositionM0 + [cosd(motorAngles(1))*lengthM0toM1 , sind(motorAngles(1))*lengthM0toM1]; %Calculate actaul position
    motorPositionM2 = motorPositionM1 + [29 -38];

    %Turn all negative values to positive
    motorAngles(1) = abs(motorAngles(1));

    %Calculate the distance from motor M1 to the desired position 
    distanceX = desiredPosition(1) - motorPositionM1(1);
    distanceY = desiredPosition(2) - motorPositionM1(2);
    distance = sqrt( distanceX^2 + distanceY^2 );

    %Calculate the angle of motor M1 to reach the desired position
    motorAngles(2) = pi/2 - acos(distance / linkLengths(3));
    if distanceX >= 0 && distanceY >= 0
        motorAngles(2) = -motorAngles(2);
    end

    %Calculate the angle of motor M2 so that link e is parallel
    motorAngles(3) = parallelMotorAnglet2(motorAngles(2),motorPositionM1,motorPositionM2,linkLengths);

    %Convert the motor angles to an int16 and remap the angles from 0-359 to 0-65535
    motorAngles = int16(rad2deg(motorAngles) * 65535 / 359);

end




