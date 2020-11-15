function [motorAngles] = approachObject(linkLengths, currentmotorAnglet1,distanceToObject)


    
    if currentmotorAnglet1 > pi/2
        angleInTrinagle = pi/2 - currentmotorAnglet1;
        currentDistance =  sin(angleInTrinagle) * linkLengths(3);
        distance = currentDistance + distanceToObject;
               
    else
        angleInTrinagle = currentmotorAnglet1 - pi/2;
        currentDistance =  sin(angleInTrinagle) * linkLengths(3);
        distance = currentDistance - distanceToObject;
        
    end
    
    %Calculate the angle of motor M1 to reach the desired position
    motorAngles(2) = pi/2 - acos(distance / linkLengths(3));

    %Calculate the angle of motor M2 so that link e is parallel
    motorAngles(3) = parallelMotorAnglet2(motorAngles(2),motorPositionM1,motorPositionM2,linkLengths);

    %Convert the motor angles to an int16 and remap the angles from 0-359 to 0-65535
    motorAngles = int16(rad2deg(motorAngles) * 65535 / 359);

end