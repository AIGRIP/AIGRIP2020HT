function [singature] = GetARsing(angles,Y,X,degreesToMeasure)

    singature = zeros( length(degreesToMeasure),1 );

    for jj = 1:length(degreesToMeasure)

        % Warning if defMeas is less than angCP.
        [~,indA] = min( abs( degreesToMeasure(jj)-angles));
        singature(jj) = sqrt(X(indA)^2+Y(indA)^2);

    end

    %singature = normalize(singature,'norm');
    
end

