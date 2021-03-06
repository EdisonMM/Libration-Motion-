m = 1;
M = 10;
R = 1;
k = m/M;
lambda = k/(1+k);

x = linspace(-1.4,1.4);
y = linspace(-1.4,1.4);

[x,y] = meshgrid(x,y);
S = sqrt(y.^2 + (x + lambda * R).^2);
s = sqrt(y.^2 + (x - (1 - lambda)*R).^2);
U = -2*(1-lambda)*R./S - 2*lambda*R./s - (x.^2 + y.^2)/R^2;

%L1
x1 = 0.621;
y1 = 0;

%L2
x2 = 1.25;
y2 = 0;

%L3
x3 = -1.025;
y3 = 0;

%L4
x4 = (M - m)*R/(2*(M + m));
y4 = R*sin(pi/3);

%L5
x5 = x4;
y5 = -y4;

contourf(x, y, U, 2000, 'blue');
%text(0, 0, "0", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');
text(x1, y1, "\leftarrow L_1", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');
text(x2, y2, "\leftarrow L_2", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');
text(x3, y3, "\leftarrow L_3", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');
text(x4, y4, "\leftarrow L_4", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');
text(x5, y5, "\leftarrow L_5", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');
%colorbar;
hold on


%%% NOW WE NEED Tquiver(T(:,1),T(:,2),T(:,3),T(:,4))O FIGURE OUT THE DIRECTION OF THE EFFECTIVE FORCES NEAR THE LAGRANGE POINTS

%%% TO DO THIS, WE PLOT THE GRADIENT ALREADY CALCULATED BY THE C-PROGRAM

input_file = 'gradient_results.csv';
T = readtable(input_file);

contourf(x, y, U, 2000, 'blue');
%text(0, 0, "0", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');
text(x1, y1, "\leftarrow L_1", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');
text(x2, y2, "\leftarrow L_2", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');
text(x3, y3, "\leftarrow L_3", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');
text(x4, y4, "\leftarrow L_4", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');
text(x5, y5, "\leftarrow L_5", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');


q = quiver(T{:,1},T{:,2},T{:,3},T{:,4});
q.Color = 'black';
q.LineWidth = 3.0;
q.MaxHeadSize = 8.50;
q.MarkerSize = 12;

hold off

%%%%%%%%% NOW WE NEED TO PLOT THE STABLE ORBITS NEAR L4 AND L5


