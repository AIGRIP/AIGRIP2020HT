function Ff = friction_calc(T,a_tol,sf,my)
    % input diameters, weight and mode
    % input acceleration tolareans
    % input sfty factor
    % input friction kofficient 
    % output Force required for gras and diameter
    g = 9.82;
    Fm = (0.001*T(:,2)*(g+a_tol)*sf)./my;
    
    Ff = zeros(2,length(Fm));
    for i = 1:length(Fm)
        if T(i,3) == 1 % grasp
            Ff(2,i*2-1) = Fm(i)/3;
            Ff(1,i*2-1) = T(i,1);
        end
        
        if T(i,4) == 1  % parallel / pinch
            Ff(2,i*2) = Fm(i)/2;
            Ff(1,i*2) = T(i,1);
        end
    end
end