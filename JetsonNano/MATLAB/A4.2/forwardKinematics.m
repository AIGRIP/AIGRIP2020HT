function [jointPostions, opticalSensorPosition] = forwardKinematics(linkLengths, motorPositionM1,motorAnglet1,motorAnglet2)

    %This function Caluclates the forward kinematics of the gripper.
    
    %Input:
    %linkLengths = 1x5 array with the lengths of all five links in the order
    %a,b,c,d,e. The lengths are in mm;
    
    %motorPositionM1 =  1x2 array with the x and y coordinates of motor M1.
    %The coordinates are relative to the palm center
    
    %motorAnglet1 = Angle of motor M1 in rad
    
    %motorAnglet2 = Angle of motor M1 in rad

    %Output:
    %jointPostions =  2x5 array with the postions of all four joints in the order
    %A,B,C,E
    
    %opticalSensorPosition = 1x2 array with the x and y coordinates of
    %optical sensor. The coordinates are relative to the palm center
    
    %Calculate the postion of motor M2 relative to motor M1
    motorPositionM2 = motorPositionM1 + [29 -38];

    
    linkLengtha = linkLengths(1);
    linkLengthb = linkLengths(2);
    linkLengthc = linkLengths(3);
    linkLengthd = linkLengths(4);
    linkLengthe = linkLengths(5);



    % Calculate the norm for joint A to joint C, joint A to motor M1 and
    % joint C to motor M2
    normAC = sqrt((motorPositionM2(1)+linkLengtha*cos(motorAnglet2)+motorPositionM1(1)+linkLengthc*sin(motorAnglet1))^2+(motorPositionM2(2)+linkLengtha*sin(motorAnglet2)+motorPositionM1(2)-linkLengthc*cos(motorAnglet1))^2);
    normAM1 = sqrt((motorPositionM2(1)+linkLengtha*cos(motorAnglet2)-motorPositionM1(1))^2+(motorPositionM2(2)+linkLengtha*sin(motorAnglet2)-motorPositionM1(2))^2);
    normCM2 = sqrt((motorPositionM2(1)-motorPositionM1(1)+linkLengthc*sin(motorAnglet1))^2+(motorPositionM2(2)-motorPositionM1(2)-linkLengthc*cos(motorAnglet1))^2);

    %Calculate the angles Theta, Alfa and Beta
    thetaL = acos((linkLengthc^2+normAC^2-normAM1^2)/(2*linkLengthc*normAC));
    alfaL = acos((normAC^2+linkLengtha^2-normCM2^2)/(2*normAC*linkLengtha));
    thetaV = acos((normAC^2+linkLengthd^2-linkLengthb^2)/(2*normAC*linkLengthd));
    alfaV = acos((linkLengthb^2+normAC^2-linkLengthd^2)/(2*linkLengthb*normAC));

    angleTheta = thetaL + thetaV;
    angleAlfa = alfaL + alfaV;
    angleBeta = acos((linkLengthd^2+linkLengthb^2-normAC^2)/(2*linkLengthd*linkLengthb));

    %Calculate every joint postion. And the postion of the optical sensor
    jointPositionA = [motorPositionM2(1)+linkLengtha*cos(motorAnglet2) motorPositionM2(2)+linkLengtha*sin(motorAnglet2)];
    jointPositionB = [motorPositionM2(1)+linkLengtha*cos(motorAnglet2)+linkLengthb*cos(pi-angleAlfa+motorAnglet2) motorPositionM2(2)+linkLengtha*sin(motorAnglet2)+linkLengthb*sin(pi-angleAlfa+motorAnglet2)];
    jointPositionC = [motorPositionM1(1)+(linkLengthc*-sin(motorAnglet1)) motorPositionM1(2)+(linkLengthc*cos(motorAnglet1))];
    jointPositionE = [motorPositionM1(1)-linkLengthc*sin(motorAnglet1)+linkLengthe*sin((pi/2)-angleTheta-motorAnglet1) motorPositionM1(2)+linkLengthc*cos(motorAnglet1)+linkLengthe*cos((pi/2)-angleTheta-motorAnglet1)];
    opticalSensorPosition = [motorPositionM1(1)-linkLengthc*sin(motorAnglet1)+(linkLengthe/2)*sin((pi/2)-angleTheta-motorAnglet1) motorPositionM1(2)+linkLengthc*cos(motorAnglet1)+(linkLengthe/2)*cos((pi/2)-angleTheta-motorAnglet1)]; 

    jointPostions = [jointPositionA ; jointPositionB ; jointPositionC ; jointPositionE];
end

