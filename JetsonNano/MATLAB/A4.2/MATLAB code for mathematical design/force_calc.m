function [FN,FD,M2tr,t2] = force_calc(Dim,t1r,par)
    M1t = 1.5; %N
    M1 = [Dim(1) Dim(2)];
    M2 = [Dim(3) Dim(4)];
    a = Dim(5);
    b = Dim(6);
    c = Dim(7);
    d = Dim(8);
    e = Dim(9);
    delta_e = Dim(10);    
    
    FN = zeros(2,size(t1r,2));
    FD = zeros(size(t1r));
    M2tr = zeros(size(t1r));
    for i = 1:length(t1r)
        t1 = t1r(i);
        if par == 1
            [t2, t2pd] = t1tot2(t1,M1,M2,a,b,c,d);
        end

        g = sqrt((M2(1)+a*cos(t2)-M1(1)+c*sin(t1))^2+(M2(2)+a*sin(t2)-M1(2)-c*cos(t1))^2);
        AM1 = sqrt((M2(1)+a*cos(t2)-M1(1))^2+(M2(2)+a*sin(t2)-M1(2))^2);
        CM2 = sqrt((M2(1)-M1(1)+c*sin(t1))^2+(M2(2)-M1(2)-c*cos(t1))^2);
        beta = acos((d^2+b^2-g^2)/(2*d*b));
        theta = acos((c^2+g^2-AM1^2)/(2*c*g)) + acos((g^2+d^2-b^2)/(2*g*d));
        alfa = acos((g^2+a^2-CM2^2)/(2*g*a)) + acos((b^2+g^2-d^2)/(2*b*g));

        fc = M1t/(0.001*c)*[cos((3*pi/2)-theta) sin((3*pi/2)-theta)];
        fb_r = (-fc(1)*delta_e)/((cos(beta)*delta_e)+(sin(beta)*d));
        
        fbmax = (1.5*sin(pi-alfa))/(0.001*a);
        fc_r = M1t/(0.001*c);
        if fb_r > fbmax
            fb_r = fbmax;
            fc_r = -((cos(beta)*delta_e)+(sin(beta)*d))*fb_r/(cos((3*pi/2)-theta)*delta_e);
            fc = fc_r*[cos((3*pi/2)-theta) sin((3*pi/2)-theta)];
        end        
        fb = fb_r*[cos(beta) sin(beta)];

        FN(1,i) = -fc(1)-fb(1);
        FN(2,i) = M1(1)+(c*-sin(t1)); % length from midpoint
        FD(i) = -fc(2)-fb(2);
        M2tr(i) = (fb_r*0.001*a)/sin(pi-alfa);
    end
   
end

