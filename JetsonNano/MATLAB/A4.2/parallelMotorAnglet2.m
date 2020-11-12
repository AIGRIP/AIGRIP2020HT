function [motorAnglet2] = parallelMotorAnglet2(motorAnglet1,motorPositionM1,motorPositionM2,linkLengtha,linkLengthb,linkLengthc,linkLengthd)

    %Calc
    jointPositionB = [motorPositionM1(1)+(linkLengthc*-sin(motorAnglet1))+linkLengthd  motorPositionM1(2)+(linkLengthc*cos(motorAnglet1))] - motorPositionM2; % C + d - M2
    
    angleAlfa = pi-acos((linkLengtha^2+linkLengthb^2-(norm(jointPositionB))^2)/(2*linkLengtha*linkLengthb));
    
    motorAnglet2 = atan((((jointPositionB(2)*(linkLengtha+linkLengthb*cos(angleAlfa)))-(jointPositionB(1)*(linkLengthb*sin(angleAlfa)))))/((jointPositionB(1)*(linkLengtha+linkLengthb*cos(angleAlfa)))+(jointPositionB(2)*(linkLengthb*sin(angleAlfa)))));   
    
end

