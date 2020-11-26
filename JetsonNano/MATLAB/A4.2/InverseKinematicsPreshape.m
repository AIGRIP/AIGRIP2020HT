function [motorAngles] = InverseKinematicsPreshape(linkLengths, desiredPosition, normalStableLine, fingerNum)

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
    %with the possiblePosition creates the line which represents the 
    %direction the finger should be facing. The coordinates are 
    %relative to the palm center

    %fingerNum = number to determine what finger is getting calculated. 
    %The number is between 0-2. 0 is for the stationary finger and 
    %then the sequense countines clockwise  
    
    %Output:
    %motorAngles = 1X3 array with three motor angles one for each motro in a
    %finger. The order of the motors in the array is M0,M1,M2. 

    motorAngles = zeros(1,3);
    if fingerNum ~= 0 
        %Set the posistion of motor M0 relative to the center of the palm
        if fingerNum == 1
            motorPositionM0 = [-20,36];
        else
            motorPositionM0 = [-20,-36];
        end
        lengthM0toM1 = 38;
        %Make the direction relate to M0 position instead of palm center
        directionPosition = normalStableLine - motorPositionM0; 
        %If the directionPosition is the same as motorPositionM0 move the direction
        %in the normal direction
        if directionPosition == 0
            directionPosition = normalStableLine + desiredPosition - motorPositionM0;
        end
        %Calculate the angle that motor M0 should move to
        motorAngles(1) = angle(directionPosition(1) + directionPosition(2)*1i);

        %Change the angles to be between 0-90 degree
        if motorAngles(1) < -(pi/2)
            motorAngles(1) = motorAngles(1) + pi;
        elseif  motorAngles(1) > (pi/2)
            motorAngles(1) = motorAngles(1) - pi;
        end

        %Calculate the distance from the palm center to the poistions 
        %of motor M1 and M2
         if fingerNum == 1
            motorPositionM1 = motorPositionM0 - [cos(motorAngles(1))*lengthM0toM1 , sin(motorAngles(1))*lengthM0toM1];
         else
            motorPositionM1 = motorPositionM0 - [cos(motorAngles(1))*lengthM0toM1 , sin(motorAngles(1))*lengthM0toM1];
        end
    else
        motorAngles(1) = 0;
        motorPositionM1 = [64,0];
    end
    motorPositionM2 = [motorPositionM1(1) - 29, -38];

    %Turn all negative values to positive
    motorAngles(1) = abs(motorAngles(1));

    %Calculate the distance from motor M1 to the desired position 
    distanceX = desiredPosition(1) - motorPositionM1(1);
    distanceY = desiredPosition(2) - motorPositionM1(2);
    distance = sqrt( distanceX^2 + distanceY^2 );

    %Calculate the angle of motor M1 to reach the desired position
    motorAngles(2) = acos(distance / linkLengths(3));
    %Check if the desired point is closer to the center than the motor M0
    %position
    if norm([0,0]-desiredPosition) > norm([0,0]-motorPositionM1)
        motorAngles(2) = pi/2 + (pi/2 - motorAngles(2));
    end

    %Calculate the angle of motor M2 so that link e is parallel
    motorAngles(3) = ParallelMotorAnglet2(motorAngles(2),[motorPositionM1(1),0],motorPositionM2,linkLengths);
    
    %Add offset for the motors and change radians to degree
    if fingerNum == 0
        motorAngles = [0 150 60] + rad2deg(motorAngles);   
    elseif fingerNum == 1
        motorAngles = [150 150 60] + rad2deg(motorAngles); 
    else
        motorAngles = [0 150 60] + rad2deg(motorAngles) ;
        motorAngles(1) = 90 - motorAngles(1) + 60;
    end
    
    %Convert the motor angles to an int16 and remap the angles from 0-300 to 0-65535
    motorAngles = uint16(motorAngles * (65535 / 300));

end
