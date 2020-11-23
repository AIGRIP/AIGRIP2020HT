function [ang] = XYtoAngle(x,y)
% Convert length vectors to angles.
    
    ang= zeros(length(x),1);

    % RH+
    RHPi = (y>=0) & (x>=0);
    ang( RHPi ) = -1*atan2(y(RHPi),x(RHPi))+pi;
    
    % LH-
    LHNi = (y<=0) & (x<=0);
    ang( LHNi ) = 2*pi-atan2( abs(y(LHNi)),abs(x(LHNi)) );
    
    %LH+
    LHPi = (y>=0) & (x<=0);
    ang( LHPi ) = atan2( abs(y(LHPi)),abs(x(LHPi)) );
    
    %RH-
    RHNi = (y<=0) & (x>=0);
    ang( RHNi ) = atan2( abs(y(RHNi)),abs(x(RHNi)) )+pi;
    
    
    % ang(ang<0) = ang(ang<0)+2*pi;
    
end

