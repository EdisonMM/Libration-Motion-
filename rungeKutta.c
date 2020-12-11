#include "diff_equations.h"
#include "parameters.h"
#include <stdio.h>
#include <math.h>


// This function implements the 4th order runge kutta method to solve the differential equations in diff_equations.c

void rungeKutta(float m, float M, float R, float G, float t0, float r0, float phi0, float p0, float l0, float t, float h, float results[]){

    //number of steps
    int n = (int) (t - t0)/h;

    //rk coefficients
    float k1,k2,k3,k4; 
    float l1,l2,l3,l4;
    float m1,m2,m3,m4; 
    float n1,n2,n3,n4;

    //iterate

    float r = r0, phi = phi0, p = p0, l = l0;
    for (int i=1; i<=n; i++)
    {
        //rk formula

        k1 = h*rdot(t0, m, M, R, r, phi, p, l, G);
        l1 = h*phidot(t0, m, M, R, r, phi, p, l, G);
        m1 = h*pdot(t0, m, M, R, r, phi, p, l, G);
        n1 = h*ldot(t0, m, M, R, r, phi, p, l, G);

        k2 = h*rdot(t0 + 0.5*h,m, M, R, r + 0.5*k1, phi + 0.5*l1, p + 0.5*m1, l + 0.5*n1, G);
        l2 = h*phidot(t0 + 0.5*h,m, M, R, r + 0.5*k1, phi + 0.5*l1, p + 0.5*m1, l + 0.5*n1, G);
        m2 = h*pdot(t0 + 0.5*h,m, M, R, r + 0.5*k1, phi + 0.5*l1, p + 0.5*m1, l + 0.5*n1, G);
        n2 = h*ldot(t0 + 0.5*h,m, M, R, r + 0.5*k1, phi + 0.5*l1, p + 0.5*m1, l + 0.5*n1, G);

        k3 = h*rdot(t0 + 0.5*h,m, M, R, r + 0.5*k2, phi + 0.5*l2, p + 0.5*m2, l + 0.5*n2, G);
        l3 = h*phidot(t0 + 0.5*h,m, M, R, r + 0.5*k2, phi + 0.5*l2, p + 0.5*m2, l + 0.5*n2, G);
        m3 = h*pdot(t0 + 0.5*h,m, M, R, r + 0.5*k2, phi + 0.5*l2, p + 0.5*m2, l + 0.5*n2, G);
        n3 = h*ldot(t0 + 0.5*h,m, M, R, r + 0.5*k2, phi + 0.5*l2, p + 0.5*m2, l + 0.5*n2, G);

        k4 = h*rdot(t0 + 0.5*h, m, M, R, r+k3, phi + l3, p + m3, l + n3, G);
        l4 = h*phidot(t0 + 0.5*h, m, M, R, r+k3, phi + l3, p + m3, l + n3, G);
        m4 = h*pdot(t0 + 0.5*h, m, M, R, r+k3, phi + l3, p + m3, l + n3, G);
        n4 = h*ldot(t0 + 0.5*h, m, M, R, r+k3, phi + l3, p + m3, l + n3, G);

        //update values

        r = r + (1.0/6.0) * (k1 + 2*k2 + 2*k3 + k4);
        phi = phi + (1.0/6.0) * (l1 + 2*l2 + 2*l3 + l4);
        p = p + (1.0/6.0) * (m1 + 2*m2 + 2*m3 + m4);
        l = l + (1.0/6.0) * (n1 + 2*n2 + 2*n3 + n4);

        t0 = t0 + h;
        
    }

    results[0] = r;
    results[1] = phi;
    results[2] = p;
    results[3] = l;

    return;

}

