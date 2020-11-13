
function [positionReachable]  = point_to_line(singularityPoint, possiblePosition, normalStableLines)
    
    %This function calculates how every motor in a finger should be rotated for
    %it to reach a certain point with a certain angle and with the last link
    %being parallel to the palm of the gripper

    %Input:
    %singularityPoint = 1x2 array with the x and y coordinates of the point
    
    %possiblePositions =  
    
    %normalStableLines = 
    
    %Output:
    % positionReachable = 

    %Set value of error margin
    errorMargin = 3;

    positionReachable = 0;
    
    %Calculate the distances from the normals to the singularity point.
    a = normalStableLines - possiblePosition;
    b = a.*flip(singularityPoint);
    distance = abs(b(2) - b(1) + normalStableLines(1)*possiblePosition(2) - normalStableLines(2)*possiblePosition(1)) / norm(a);

    %Pick the first distance in the list that is lower than the error margin
    if distance < errorMargin
        positionReachable = 1;
    end
    
    
end
      
      