m = 1;
M = 10;
R = 1;
k = m/M;
lambda = k/(1+k);

x = linspace(-1.5,1.5);
y = linspace(-1.5,1.5);

[x,y] = meshgrid(x,y);
S = sqrt(y.^2 + (x + lambda * R).^2);
s = sqrt(y.^2 + (x - (1 - lambda)*R).^2);
U = -2*(1-lambda)*R./S - 2*lambda*R./s - (x.^2 + y.^2)/R^2;
x1 = 0.621;
y1 = 0;

x2 = 1.25;
y2 = 0;

contourf(x, y, U, 2000, 'blue');
text(x1, y1, "\leftarrow L_1", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');
text(x2, y2, "\leftarrow L_2", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');

colorbar;