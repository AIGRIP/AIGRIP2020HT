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
    
    motorAngles = zeros(1,3);

    %Convert the steps into radians
    currentmotorAnglet1 = deg2rad(currentMotorM1Steps *(300/65535) - 150);
    motorAngles(1) = currentMotorM0Steps;
    
    %Calculate the new angle of motor M1
    if currentmotorAnglet1 > pi/2
        %Calculate current distance from the joint position c to
        %position of motor M1
        angleInTriangle = currentmotorAnglet1 - pi/2;
        currentDistance =  sin(angleInTriangle) * linkLengths(3);
        distance = currentDistance - distanceToObject;
        %Check if the new angle goes over pi/2 radians
        motorAngles(2) = acos(abs(distance) / linkLengths(3));
        if distance > 0
            motorAngles(2) = pi/2 + (pi/2 - motorAngles(2));
        end
    else
        %Calculate current distance from the joint position c to
        %position of motor M1
        angleInTriangle = pi/2 - currentmotorAnglet1;
        currentDistance =  sin(angleInTriangle) * linkLengths(3);
        distance = currentDistance + distanceToObject;
        motorAngles(2) = acos(distance / linkLengths(3));
    end 
   

    motorPositionM1 = [0,0];
    motorPositionM2 = [-29,-38];
    %Calculate the angle of motor M2 so that link e is parallel
    motorAngles(3) = ParallelMotorAnglet2(motorAngles(2),motorPositionM1,motorPositionM2,linkLengths);

    %Add offset for the motors and change radians to degree
    motorAngles(2) = rad2deg(motorAngles(2)) + 150;
    motorAngles(3) = rad2deg(motorAngles(3)) + 60;
    
    %Convert the motor angles to an uint16 and remap the angles from 0-300 to 0-65535
    motorAngles(2) = uint16(motorAngles(2) * 65535 / 300);
    motorAngles(3) = uint16(motorAngles(3) * 65535 / 300);


end