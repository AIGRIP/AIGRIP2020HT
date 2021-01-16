function [jointPostions , opticalSensorPosition] = ForwardKinematics(linkLengths, motorPositionM1,motorAnglet1,motorAnglet2)

    %This function Caluclates the forward kinematics of the gripper.
    
    %Input:
    %linkLengths                - 1x5 array with the lengths of all five links in the order
    %                               a,b,c,d,e. The lengths are in mm;
    %motorPositionM1            - 1x2 array with the x and y coordinates of motor M1.
    %                               The coordinates are relative to the palm center
    %motorAnglet1               - Angle of motor M1 in rad
    %motorAnglet2               - Angle of motor M1 in rad

    %Output:
    %jointPostions              - 1x8 array with the postions of all four joints in the order
    %                               Ax,Ay,Bx,By,Cx,Cy,Ex,Ey           
    %opticalSensorPosition      - 1x2 array with the x and y coordinates of
    %                               optical sensor. The coordinates are relative to the palm center
   
    
    %Calculate the postion of motor M2 relative to motor M1
    motorPositionM2 = motorPositionM1 + [-29 -38];
    
    motorAnglet2 = motorAnglet2 + pi/2;
    
    linkLengtha = linkLengths(1);
    linkLengthb = linkLengths(2);
    linkLengthc = linkLengths(3);
    linkLengthd = linkLengths(4);
    linkLengthe = linkLengths(5);

    
    %Calculate the postions of joint A and C
    jointPositionA = [motorPositionM2(1)+linkLengtha*cos(motorAnglet2) motorPositionM2(2)+linkLengtha*sin(motorAnglet2)]   
    jointPositionC = [motorPositionM1(1)+linkLengthc*cos(motorAnglet1) motorPositionM1(2)+linkLengthc*sin(motorAnglet1)]

    %Calculate the norm for joint A to joint C
    normAC = norm(jointPositionA - jointPositionC);

    %Calculate the postions of joint B
    angleAlfa1 = acos(abs(jointPositionA(1)- jointPositionC(1))/normAC);
    angleAlfa2 = acos((normAC^2 + linkLengthb^2 - linkLengthd^2) / (2*normAC*linkLengthb));
    jointPositionB = jointPositionA + [linkLengthb*cos(angleAlfa1+angleAlfa2) linkLengthb*sin(angleAlfa1+angleAlfa2)];
    
    %Calculate the postions of joint E and optical sensor postion
    angleBE = atan(linkLengthe/linkLengthd);
    normBE = sqrt(linkLengthe^2 + linkLengthd^2);
    jointPositionE = jointPositionB + [normBE*cos(angleBE) normBE*sin(angleBE)];
    opticalSensorPosition = (jointPositionE + jointPositionC)/2;

    %jointPostions = [jointPositionA jointPositionB jointPositionC jointPositionE];
    
    jointPostions = [jointPositionA jointPositionB jointPositionC jointPositionE];
    
    
    
end

