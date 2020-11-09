function [t2p, t2pd] = t1tot2(t1,M1,M2,a,b,c,d)
    Bn = [M1(1)+(c*-sin(t1))+d  M1(2)+(c*cos(t1))] - M2; % C + d - M2
    alf = pi-acos((a^2+b^2-(norm(Bn))^2)/(2*a*b));
    t2p = atan((((Bn(2)*(a+b*cos(alf)))-(Bn(1)*(b*sin(alf)))))/((Bn(1)*(a+b*cos(alf)))+(Bn(2)*(b*sin(alf)))));
    t2pd = rad2deg(t2p); % t2p in deg
end

