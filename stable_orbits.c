
#include "helper_subroutines.h"
#include "rungeKutta.h"

#include <math.h>



//computing orbit near L4
void l4_orbit(float x, float y, float epsilon, float m, float M, float R, float G, float t0, float tmax, int N, float h)
{
    //getting initial conditions
    x = x + epsilon;
    y = y + epsilon;
    float phi0 = atan(y/x);
    float r0 = sqrt(pow(x,2) + pow(y, 2));
    float p0 = 0;
    float l0 = 0;

    float t_array[N], x_array[N], y_array[N];

    float dt = (tmax - t0)/N;

    //performing runge kutta in the interval t0 to tmax for N points
    for (int i=0; i < N; i++)
    {
        float result[4];

        float t = t0 + i*dt;
        t_array[i] = t;

        rungeKutta(m, M, R, G, t0, r0, phi0, p0, l0, t, h, result);

        x_array[i] = result[0] * cos(result[1]);
        y_array[i] = result[0] * sin(result[1]);

    }

    //writing results
    char* fileName = "l4_orbits.csv";

    write_results(N, t_array, x_array, y_array, fileName);

}

//computing the orbit near L5
void l5_orbit(float x, float y, float epsilon, float m, float M, float R, float G, float t0, float tmax, int N, float h)
{
    //getting initial conditions
    x = x + epsilon;
    y = y + epsilon;
    float phi0 = atan(y/x);
    float r0 = sqrt(pow(x,2) + pow(y, 2));
    float p0 = 0;
    float l0 = 0;

    float t_array[N], x_array[N], y_array[N];

    //performing runge kutta in the interval t0 to tmax for N points
    float dt = (tmax - t0)/N;

    for (int i=0; i < N; i++)
    {
        float result[4];

        float t = t0 + i*dt;
        t_array[i] = t;

        rungeKutta(m, M, R, G, t0, r0, phi0, p0, l0, t, h, result);

        x_array[i] = result[0] * cos(result[1]);
        y_array[i] = result[0] * sin(result[1]);

    }

    //writing results
    char* fileName = "l5_orbits.csv";

    write_results(N, t_array, x_array, y_array, fileName);

}