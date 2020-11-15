
function [positionReachable]  = point_to_line(singularityPoint, possiblePosition, normalStableLine)
    
    %This function takes a possible postion and angle for the gripper
    %finger to move to. Then the function decides if the position is
    %reachable or not.

    %Input:
    %singularityPoint = 1x2 array with the x and y coordinates of the point
    %where the finger is rotating around. The coordinates are relative 
    %to the palm center
    
    %possiblePosition =  1x2 array with the x and y coordinates of a 
    %possible point for the gripper . The coordinates are 
    %relative to the palm center

    %normalStableLine = 1x2 array with the x and y coordinates that together
    %with the possiblePosition creates the line which represents the 
    %direction the finger should be facing. The coordinates are 
    %relative to the palm center
    
    %Output:
    % positionReachable = Zero if possiblePosition is not reachable.
    % Non_zero if possiblePosition is reachable

    %Set value of error margin
    errorMargin = 3;

    positionReachable = 0;
    
    %Calculate the distances from the normals to the singularity point.
    a = normalStableLine - possiblePosition;
    b = a.*flip(singularityPoint);
    distance = abs(b(2) - b(1) + normalStableLine(1)*possiblePosition(2) - normalStableLine(2)*possiblePosition(1)) / norm(a);

    %Pick the first distance in the list that is lower than the error margin
    if distance < errorMargin
        positionReachable = 1;
    end
    
    
end
      
      