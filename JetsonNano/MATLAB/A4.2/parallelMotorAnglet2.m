function [motorAnglet2] = parallelMotorAnglet2(motorAnglet1,motorPositionM1,motorPositionM2,linkLengths)





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

