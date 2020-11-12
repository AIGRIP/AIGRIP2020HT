
function desiredPosition = point_to_line(singularityPoint, possiblePositions, normalStableLine)
    

    %Set value of error margin
    errorMargin = 30;

    %Calculate the distances from the normals to the singularity point.
    a = normalStableLine - possiblePositions;
    b = a.*flip(singularityPoint);
    distance = abs(b(:,2) - b(:,1) + normalStableLine(:,1).*possiblePositions(:,2) - normalStableLine(:,2).*possiblePositions(:,1)) ./ vecnorm(a')';

    %Pick the first distance in the list that is lower than the error margin
    firstTrueIdx = find(distance < errorMargin);
    desiredPosition = [possiblePositions(firstTrueIdx(1),:) ; normalStableLine(firstTrueIdx(1),:)];
end
      
      