
m = 1;
M = 30;

R = 1;
k = m/M;
lambda = k/(1+k);
w = 1;



syms r(t) phi(t) p(t) l(t)

lambda = k/(1 + k);

S = ( (r*sin(phi))^2 + (r*cos(phi) + lambda * R)^2)^0.5;

s = ( (r*sin(phi))^2 + (r*cos(phi) - (1 - lambda)*R)^2 )^0.5;

ode1 = diff(r) == p;

ode2 = diff(phi) == l/(r^2) - w;

ode3 = diff(p) == (l^2/r^3) - w^2 * R^3 * (1-lambda) * (r + lambda * R * cos(phi))/(S^3) - w^2 * R^3 * lambda * (r - (1 - lambda)*R*cos(phi))/s^3;

ode4 = diff(l) == w^2 * R^4 * lambda * (1 - lambda) * (1/S^3 - 1/s^3)*r*sin(phi);

odes = [ode1; ode2; ode3; ode4];

S = dsolve(odes);

rSol(t) = S.r;
phiSol(t) = S.phi;
pSol(t) = S.p;
lSol(t) = S.l;

