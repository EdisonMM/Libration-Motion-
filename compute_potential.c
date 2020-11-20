#include "parameters.h"
#include "diff_equations.h"
#include "helper_subroutines.h"
#include "rungeKutta.h"
#include <math.h>

//returns the dimensionless potetial
float potential(float m, float M, float R, float G, float r, float phi, float p, float l){

    float S_val = S(m, M, R, r, phi, p, l, G);
    float s_val = s(m, M, R, r, phi, p, l, G);
    float lamda_val = lamda(m, M);

    return -2 * (1 - lamda_val) * (R/S_val) - 2*lamda_val*(R/s_val) - (pow(r,2)/pow(R,2));

}

int main(){

    float t0, tmax, r0, phi0, p0, l0, m, M, R, G, h;
    int N;

    t0 = 0;
    tmax = 100;
    r0 = 1;
    phi0 = 0;
    p0 = 1;
    l0 = 1;
    m = 1;
    M = 100;
    R = 1;
    G = 6.67e-11;
    //Number of time steps
    N = 1000;
    h = 0.2;

    float t_array[N], r_array[N], phi_array[N], p_array[N], l_array[N], U_array[N];

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
        U_array[i] = potential(m, M, R, G, result[0], result[1], result[2], result[3]);
    }

    write_results(N, t_array, r_array, phi_array, p_array, l_array, U_array);

    return 0;

}