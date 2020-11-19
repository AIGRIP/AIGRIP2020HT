function [ang] = XYtoAngle(x,y)
% Convert length vectors to angles.
    
    ang= zeros(length(x),1);
    
    % RH+
    RHPi = (y>=0) & (x>=0);
    ang( RHPi ) = atan2(y(RHPi),x(RHPi));
    
    % LH-
    LHNi = (y<=0) & (x<=0);
    ang( LHNi ) = atan2( abs(y(LHNi)),abs(x(LHNi)) )+pi;
    
    %LH+
    LHPi = (y>=0) & (x<=0);
    ang( LHPi ) = -1*atan2( abs(y(LHPi)),abs(x(LHPi)) )+pi;
    
    %RH-
    RHNi = (y<=0) & (x>=0);
    ang( RHNi ) = 2*pi-atan2( abs(y(RHNi)),abs(x(RHNi)) );
    
    % ang(ang<0) = ang(ang<0)+2*pi;
    
end

