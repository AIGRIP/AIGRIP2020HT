function [motorAnglet2] = parallelMotorAnglet2(motorAnglet1,motorPositionM1,motorPositionM2,linkLengths)

    %This function Caluclates what the angle motor M2 should have to make 
    %link e parallel 
    
    %Input:
    
    %motorAnglet1 = Angle of motor M1 in rad
    
    %motorPositionM1 =  1x2 array with the x and y coordinates of motor M1.
    %The coordinates are relative to the palm center
    
    %motorPositionM2 =  1x2 array with the x and y coordinates of motor M2.
    %The coordinates are relative to the palm center
    
    %linkLengths = 1x5 array with the lengths of all five links in the order
    %a,b,c,d,e

    %Output:
    %motorAnglet2 = Angle of motor M1 in rad


    %Set the appropriate lengths for the links
    linkLengtha = linkLengths(1);
    linkLengthb = linkLengths(2);
    linkLengthc = linkLengths(3);
    linkLengthd = linkLengths(4);

    %Calculate the position of joint B when link d lies 
    %perpendicular to link e
    jointPositionB = [motorPositionM1(1)+(linkLengthc*-sin(motorAnglet1))+linkLengthd  motorPositionM1(2)+(linkLengthc*cos(motorAnglet1))] - motorPositionM2;
    %Calculate the angle alfa
    angleAlfa = pi-acos((linkLengtha^2+linkLengthb^2-(norm(jointPositionB))^2)/(2*linkLengtha*linkLengthb));
    %Calculate the angle of motor M2
    motorAnglet2 = atan((((jointPositionB(2)*(linkLengtha+linkLengthb*cos(angleAlfa)))-(jointPositionB(1)*(linkLengthb*sin(angleAlfa)))))/((jointPositionB(1)*(linkLengtha+linkLengthb*cos(angleAlfa)))+(jointPositionB(2)*(linkLengthb*sin(angleAlfa)))));   
    
end

