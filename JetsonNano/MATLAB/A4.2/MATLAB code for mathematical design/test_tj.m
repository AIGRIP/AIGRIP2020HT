%M = 1:0.1:5;
%A = 0.001:0.0001:0.01;
h = 10;%1:10; %mm
b = 5;%20; %mm
E = 3.5*10^9;
m = 0.001;


sigma = (1.5*6)/(m*b*((m*h)^2)*2); % Pa
toj = sigma/E; % %

%plot(F,e)

%%
N = 75; 
g = 0.0001; % kvadrat centimeter
tryck = 100*((N/g)/E); % %