#include <stdio.h>
#include <math.h>

//defining the parameters

float k(float m, float M)
{
    return m/M;
}

float lamda(float m, float M){

    return k(m, M)/(1 + k(m, M));
}

float rm(float m, float M, float R){

    return (1 - lamda(m, M))*R;
}

float rM(float m, float M, float R){

    return lamda(m, M)*R;
}


float omega(float m, float M, float R, float G){

    //double R_cube = pow(R, 3);

    //float omega_squared = G * M/(R_cube * (1 - lamda(m, M)));

    //return pow(omega_squared, 0.5);

    return 1;
}
