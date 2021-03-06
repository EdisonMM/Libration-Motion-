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
    p0 = 1;
    l0 = 0;
    R = 1;
    G = 6.67e-11;

    //Number of time steps
    N = 1000;
    h = 0.2;
    xmin = -1.4;
    ymin = -1.4;
    xmax = 1.4;
    ymax = 1.4;

    //Lagrange Points L4 and L5
    
    float pi = 3.14159265359;

    float x4 = (M - m)*R/(2*(M + m));
    float y4 = R*sin(pi/3);

    float x5 = x4;
    float y5 = -y4;

    //float t_array[N], r_array[N], phi_array[N], p_array[N], l_array[N], x_array[N], y_array[N];

    /*
    float dt = (tmax - t0)/N;

    U_array[0] = potential(m, M, R, G, r0, phi0, p0, l0);

    for (int i=0; i < N; i++)
    {
        float result[4];

        float t = t0 + i*dt;
        t_array[i] = t;

        rungeKutta(m, M, R, G, t0, r0, phi0, p0, l0, t, h, result);

        r_array[i] = result[0];
        phi_array[i] = result[1];
        p_array[i] = result[2];
        l_array[i] = result[3];
        x_array[i] = result[0] * cos(result[1]);
        y_array[i] = result[0] * sin(result[1]);
        U_array[i] = potential(m, M, R, G, result[0], result[1], result[2], result[3]);
    } */

    l4_orbit(x4, y4, h, m, M, R, G, t0, tmax, N, h);
    l5_orbit(x5, y5, h, m, M, R, G, t0, tmax, N, h);

    //write_results(N, t_array, r_array, phi_array, p_array, l_array, x_array, y_array, U_array);
    //write_parameters(N, t0, tmax, r0, phi0, p0, l0, m, M, R, G, h);
    compute_gradient(m, M, R, G, xmin, xmax, ymin, ymax, p0, l0, 0.6*h);

    return 0;

}