#include "parameters.h"
#include "diff_equations.h"
#include "helper_subroutines.h"
#include "rungeKutta.h"
#include "potential.h"
#include "gradient.h"
#include "stable_orbits.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[]){

    float t0, tmax, p0, l0, m, M, R, G, h, xmin, xmax, ymin, ymax;
    int N;

    m = 1;
    M = 10;

    char* str1 = "-m";
    char* str2 = "-M";

    for (int j = 0; j < argc; j++)
    {
        if (strcmp(argv[j], str1) == 0)
        {

            m = atof(argv[j+1]);
        }

        if (strcmp(argv[j], str2) == 0)
        {
            M = atof(argv[j+1]);
        }

    }

    t0 = 0;
    tmax = 100;
    //r0 = 1;
    //phi0 = 0;
    p0 = 0;
    l0 = 0;
    R = 1;
    G = 6.67e-11;

    //Number of time steps
    N = 100;
    h = 0.2;
    xmin = -1.4;
    ymin = -1.4;
    xmax = 1.4;
    ymax = 1.4;

    //Lagrange Points L4 and L5
    
    float pi = 3.14159265359;

    float x4 = R/2;
    float y4 = (R)*sin(pi/3);

    float x5 = x4;
    float y5 = -y4;

    l4_orbit(x4, y4, 0, m, M, R, G, t0, tmax, N, 0.1*h);
    l5_orbit(x5, y5, 0, m, M, R, G, t0, tmax, N, 0.1*h);

    //write_parameters(N, t0, tmax, r0, phi0, p0, l0, m, M, R, G, h);

    compute_gradient(m, M, R, G, xmin, xmax, ymin, ymax, p0, l0, 0.6*h);

    return 0;

}