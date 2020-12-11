
#include "gradient.h"
#include "stable_orbits.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]){

    //Initialize parameters
    float t0, tmax, p0, l0, m, M, R, G, h, xmin, xmax, ymin, ymax;
    int N;

    //default mass values
    m = 1;
    M = 10;

    // getting mass values if provided by the user
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

    //Initializing parameters
    t0 = 0;
    tmax = 100;
    p0 = 0;
    l0 = 0;
    R = 1;
    G = 6.67e-11;

    N = 100;
    h = 0.2;
    xmin = -1.5;
    ymin = -1.5;
    xmax = 1.5;
    ymax = 1.5;

    //Lagrange Points L4 and L5
    
    float pi = 3.14159265359;

    float x4 = R/2;
    float y4 = (R)*sin(pi/3);

    float x5 = x4;
    float y5 = -y4;

    //Computing the gradient of the potential

    compute_gradient(m, M, R, G, xmin, xmax, ymin, ymax, p0, l0, 0.6*h);

    //Computing the orbits near L4 and L5
    l4_orbit(x4, y4, 0, m, M, R, G, t0, tmax, N, 0.1*h);
    l5_orbit(x5, y5, 0, m, M, R, G, t0, tmax, N, 0.1*h);



    return 0;

}