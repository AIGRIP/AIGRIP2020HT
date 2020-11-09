function [Aout] = fingerCalc(M1, M2, X)
    %M1 = X(1);
    %M2 = X(2);
    t1 = X(3);
    t2 = X(4);
    a = X(5);
    b = X(6);
    c = X(7);
    d = X(8);
    e = X(9);
    
    A = [M2(1)+a*cos(t2) M2(2)+a*sin(t2)];
    C = [M1(1)+(c*-sin(t1)) M1(2)+(c*cos(t1))];
    g = sqrt((M2(1)+a*cos(t2)-M1(1)+c*sin(t1))^2+(M2(2)+a*sin(t2)-M1(2)-c*cos(t1))^2);
    AM1 = sqrt((M2(1)+a*cos(t2)-M1(1))^2+(M2(2)+a*sin(t2)-M1(2))^2);
    CM2 = sqrt((M2(1)-M1(1)+c*sin(t1))^2+(M2(2)-M1(2)-c*cos(t1))^2);
    beta = acos((d^2+b^2-g^2)/(2*d*b));
    theta = acos((c^2+g^2-AM1^2)/(2*c*g)) + acos((g^2+d^2-b^2)/(2*g*d));
    alfa = acos((g^2+a^2-CM2^2)/(2*g*a)) + acos((b^2+g^2-d^2)/(2*b*g));
    B = [M2(1)+a*cos(t2)+b*cos(pi-alfa+t2) M2(2)+a*sin(t2)+b*sin(pi-alfa+t2)];
    E = [M1(1)-c*sin(t1)+e*sin((pi/2)-theta-t1) M1(2)+c*cos(t1)+e*cos((pi/2)-theta-t1)];
    
    Aout = [A B C E];
end

