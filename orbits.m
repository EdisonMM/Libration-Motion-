
m = 1;
M = 60;
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

hold on

contourf(x, y, U, 2000, 'blue');
%text(0, 0, "0", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');
text(x1, y1, "\leftarrow L_1", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');
text(x2, y2, "\leftarrow L_2", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');
text(x3, y3, "\leftarrow L_3", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');
text(x4, y4, "\leftarrow L_4", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');
text(x5, y5, "\leftarrow L_5", 'FontWeight', 'bold', 'FontSize', 13, 'color', 'red');

%%%%%%%%% NOW WE NEED TO PLOT THE STABLE ORBITS NEAR L4 AND L5

T4 = readtable('l4.csv');
T5 = readtable('l5.csv');

xo4 = T4{:,1};
yo4 = T4{:,2};

xo5 = T5{:,1};
yo5 = T5{:,2};


plot(xo4,yo4, 'color', 'green');

plot(xo5,yo5, 'color', 'green');
 
hold off
