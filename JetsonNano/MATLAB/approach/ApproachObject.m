function [motorAngles] = ApproachObject(linkLengths, currentmotorM1Steps,distanceToObject)

    %This function calculates how every motor in a finger should be rotated for
    %it to reach a certain point with a certain angle and with the last link
    %being parallel to the palm of the gripper

    %Input:
    %linkLengths = 1x5 array with the lengths of all five links in the order
    %a,b,c,d,e

    %currentmotorM1Steps =  Current postion of the motor angle. This angle
    %is measured in steps of the motor. 
    
    %distanceToObject = Distance from the finger to the object. distance is
    %in mm.

    %Output:
    %motorAngles = 1X3 array with three motor angles one for each motro in a
    %finger. The order of the motors in the array is M0,M1,M2.
    
    motorAngles = zeros(1,3);

    %Convert the steps into radians
    currentmotorAnglet1 = deg2rad(currentmotorM1Steps *(300/65535))-150;
    
    
    if currentmotorAnglet1 > pi/2
        angleInTrinagle = pi/2 - currentmotorAnglet1;
        currentDistance =  sin(angleInTrinagle) * linkLengths(3);
        distance = currentDistance + distanceToObject;
        motorAngles(2) = acos(distance / linkLengths(3));
    else
        angleInTrinagle = currentmotorAnglet1 - pi/2;
        currentDistance =  sin(angleInTrinagle) * linkLengths(3);
        distance = currentDistance - distanceToObject;
        motorAngles(2) = acos(distance / linkLengths(3)); %Fix this
    end
    
    %Calculate the angle of motor M1 to reach the desired position
    
    
    %Calculate the angle of motor M2 so that link e is parallel
    motorAngles(3) = parallelMotorAnglet2(motorAngles(2),motorPositionM1,motorPositionM2,linkLengths);

    %Add offset for the motors and change radians to degree
    motorAngles = rad2deg(motorAngles) + [0 150 48];
    
    %Convert the motor angles to an int16 and remap the angles from 0-300 to 0-65535
    motorAngles = int16(motorAngles * 65535 / 300);


end