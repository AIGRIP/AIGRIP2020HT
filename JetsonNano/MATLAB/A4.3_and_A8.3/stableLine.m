function [targetPoint, normalPoint] = stableLine(signature,degreesMeasured)
%stableLine Finds the required orientaions for the gripper to grasp an object.
%   Detailed explanation goes here

    % Resolution of possible grip positions.
    resolutionDeg = 10*pi/180;
    % Angle points for grasping on finger 1.
    degreesToMeasureFinger1 = 0:resDeg:(pi/2);
    % Measured points that belongs to finger 1.
    finger1Points = degreesMeasured(1:90);
    
    % Angle points for grasping on finger 2.
    degreesToMeasureFinger2 = (3*pi/2):resDeg:(2*pi);
    % Measured points that belongs to finger 2.
    finger1Points = degreesMeasured(270:end);
    
    
    
    comm.LinearEqualizer()
    lms

end

