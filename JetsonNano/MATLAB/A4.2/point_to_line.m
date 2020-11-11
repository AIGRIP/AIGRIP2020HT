
function desiredPosition = point_to_line(singularityPoint, possiblePositions, normalStableLine)

       errorMargin( 
       )
      a = normalStableLine - possiblePositions;
      b = a.*flip(singularityPoint);
      distance = abs(b(:,2) - b(:,1) + normalStableLine(:,1).*possiblePositions(:,2) - normalStableLine(:,2).*possiblePositions(:,1)) ./ vecnorm(a')';
      
      firstTrueIdx = find(distance < errorMargin);
      desiredPosition = [possiblePositions(firstTrueIdx(1),:) ; normalStableLine(firstTrueIdx(1),:)];
end
      
      