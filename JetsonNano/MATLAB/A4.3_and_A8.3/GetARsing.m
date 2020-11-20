function [singature,YCoordToStore,XCoordToStore] = GetARsing(angles,Y,X,degreesToMeasure)

    singature = zeros( length(degreesToMeasure),1 );
    
    XCoordToStore = zeros( length(degreesToMeasure),1 );
    YCoordToStore = zeros( length(degreesToMeasure),1 );
    
    singature = zeros( length(degreesToMeasure),1 );

    for jj = 1:length(degreesToMeasure)

        % Warning if defMeas is less than angCP.
        [~,indA] = min( abs( degreesToMeasure(jj)-angles));
        singature(jj) = sqrt(X(indA)^2+Y(indA)^2);
        % Store the cartesean coordinates.
        XCoordToStore(jj) = X(indA);
        YCoordToStore(jj) = Y(indA);
    end

    %singature = normalize(singature,'norm');
    
end

