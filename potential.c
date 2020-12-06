#include "parameters.h"
#include "diff_equations.h"
#include <math.h>

//returns the dimensionless potetial
float potential(float m, float M, float R, float G, float r, float phi, float p, float l){

    float S_val = S(m, M, R, r, phi, p, l, G);
    float s_val = s(m, M, R, r, phi, p, l, G);
    float lamda_val = lamda(m, M);

    return -2 * (1 - lamda_val) * (R/S_val) - 2*lamda_val*(R/s_val) - (pow(r,2)/pow(R,2));
}