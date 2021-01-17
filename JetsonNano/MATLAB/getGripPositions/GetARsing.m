function [signature,YCoordToStore,XCoordToStore] = GetARsing(angles,Y,X,degreesToMeasure)
% GetARsing returns the radius for the angles in "degreesToMeasure". 
%   angles              - Is the degrees of the points represented by "Y" and "X".
%   Y                   - Is the Y-coordinates for the points.
%   X                   - Is the X-coordinates for the points.
%   degreesToMeasure    - Is the angles for where the radius should be calculated.
%   singature           - Returns the radius of the angles to the closest point.
%   YCoordToStore       - Returns the Y-coordinates of the signature.
%   XCoordToStore       - Returns the X-coordinates of the signature.
    
    % Allocate space for the signature and the coordinates to return.
    signature = zeros( length(degreesToMeasure),1 );
    XCoordToStore = zeros( length(degreesToMeasure),1 );
    YCoordToStore = zeros( length(degreesToMeasure),1 );

    for jj = 1:length(degreesToMeasure)

        % Get the closest point to the angle to measure.
        [~,indA] = min( abs( degreesToMeasure(jj)-angles));
        
        % Get the radius.
        signature(jj) = sqrt(X(indA)^2+Y(indA)^2);
        % Store the cartesean coordinates.
        XCoordToStore(jj) = X(indA);
        YCoordToStore(jj) = Y(indA);
    end
    
end

