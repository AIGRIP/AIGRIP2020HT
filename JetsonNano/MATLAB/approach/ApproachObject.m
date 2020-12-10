function [motorAngles] = ApproachObject(linkLengths,currentMotorM0Steps, currentMotorM1Steps,distanceToObject)

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
    
    motorAngles = uint16(zeros(1,3));
    currentMotorM1Degrees = double(currentMotorM1Steps *(300/65535) - 150);
    %Convert the steps into radians
    currentmotorAnglet1 = deg2rad(currentMotorM1Degrees);
    motorAngles(1) = currentMotorM0Steps;
    %Calculate the new angle of motor M1
    if currentmotorAnglet1 > pi/2
        %Calculate current distance from the joint position c to
        %position of motor M1
        angleInTriangle = currentmotorAnglet1 - pi/2;
        currentDistance =  sin(angleInTriangle) * linkLengths(3);
        distance = currentDistance - distanceToObject;
        %Check if the new angle goes over pi/2 radians
        newMotorM1Rad = acos(abs(distance) / linkLengths(3));
        if distance > 0
            newMotorM1Rad = pi/2 + (pi/2 - newMotorM1Rad);
        end
    else
        %Calculate current distance from the joint position c to
        %position of motor M1
        angleInTriangle = pi/2 - currentmotorAnglet1;
        currentDistance =  sin(angleInTriangle) * linkLengths(3);
        distance = currentDistance + distanceToObject;
        newMotorM1Rad = acos(distance / linkLengths(3));
    end 
   

    motorPositionM1 = [0,0];
    motorPositionM2 = [-29,-38];
    %Calculate the angle of motor M2 so that link e is parallel
    newMotorM2Rad = ParallelMotorAnglet2(newMotorM1Rad,motorPositionM1,motorPositionM2,linkLengths);

    %Add offset for the motors and change radians to degree
    newMotorM1Rad = rad2deg(newMotorM1Rad) + 150;
    newMotorM2Rad = rad2deg(newMotorM2Rad) + 60;
    
    %Convert the motor angles to an uint16 and remap the angles from 0-300 to 0-65535
    motorAngles(2) = uint16(newMotorM1Rad * 65535 / 300);
    motorAngles(3) = uint16(newMotorM2Rad * 65535 / 300);


end