#include "parameters.h"
#include "diff_equations.h"
#include "helper_subroutines.h"
#include "rungeKutta.h"
#include "potential.h"

#include <math.h>

void l4_orbit(float x, float y, float epsilon, float m, float M, float R, float G, float t0, float tmax, int N, float h)
{
    x = x + epsilon;
    y = y + epsilon;
    float phi0 = atan(y/x);
    float r0 = sqrt(pow(x,2) + pow(y, 2));
    float p0 = 0;
    float l0 = 0;

    float t_array[N], x_array[N], y_array[N];

    float dt = (tmax - t0)/N;

    //U_array[0] = potential(m, M, R, G, r0, phi0, p0, l0);

    for (int i=0; i < N; i++)
    {
        float result[4];

        float t = t0 + i*dt;
        t_array[i] = t;

        rungeKutta(m, M, R, G, t0, r0, phi0, p0, l0, t, h, result);

        //r_array[i] = result[0];
        //phi_array[i] = result[1];
        //p_array[i] = result[2];
        //l_array[i] = result[3];
        x_array[i] = result[0] * cos(result[1]);
        y_array[i] = result[0] * sin(result[1]);
        //U_array[i] = potential(m, M, R, G, result[0], result[1], result[2], result[3]);
    }

    char* fileName = "l4_orbits.csv";

    write_results(N, t_array, x_array, y_array, fileName);

}

void l5_orbit(float x, float y, float epsilon, float m, float M, float R, float G, float t0, float tmax, int N, float h)
{
    x = x + epsilon;
    y = y + epsilon;
    float phi0 = atan(y/x);
    float r0 = sqrt(pow(x,2) + pow(y, 2));
    float p0 = 0;
    float l0 = 0;

    float t_array[N], x_array[N], y_array[N];

    float dt = (tmax - t0)/N;

    //U_array[0] = potential(m, M, R, G, r0, phi0, p0, l0);

    for (int i=0; i < N; i++)
    {
        float result[4];

        float t = t0 + i*dt;
        t_array[i] = t;

        rungeKutta(m, M, R, G, t0, r0, phi0, p0, l0, t, h, result);

        //r_array[i] = result[0];
        //phi_array[i] = result[1];
        //p_array[i] = result[2];
        //l_array[i] = result[3];
        x_array[i] = result[0] * cos(result[1]);
        y_array[i] = result[0] * sin(result[1]);
        //U_array[i] = potential(m, M, R, G, result[0], result[1], result[2], result[3]);
    }

    char* fileName = "l5_orbits.csv";

    write_results(N, t_array, x_array, y_array, fileName);

}