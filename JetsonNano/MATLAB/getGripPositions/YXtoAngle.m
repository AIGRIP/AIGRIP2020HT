function [angleRadian] = YXtoAngle(y,x)
% Convert length vectors to angles.
%   x - Is the vector in x-direction.
%   x - Is the vector in x-direction.
%   angleRadian - Returns the angle in radian for all the vectors.


    % Allocates the angles to return in radians.
    angleRadian= zeros(length(y),1);

    % Convert angles in the first quadrant. RH+
    RHPi = (x>=0) & (y>=0);
    angleRadian( RHPi ) = -1*atan2(x(RHPi),y(RHPi))+pi;
    
    % Convert angles in the third quadrant. LH-
    LHNi = (x<=0) & (y<=0);
    angleRadian( LHNi ) = 2*pi-atan2( abs(x(LHNi)),abs(y(LHNi)) );
    
    % Convert angles in the second quadrant. LH+
    LHPi = (x>=0) & (y<=0);
    angleRadian( LHPi ) = atan2( abs(x(LHPi)),abs(y(LHPi)) );
    
    % Convert angles in the fourth quadrant. RH-
    RHNi = (x<=0) & (y>=0);
    angleRadian( RHNi ) = atan2( abs(x(RHNi)),abs(y(RHNi)) )+pi;
    
    
    
end

