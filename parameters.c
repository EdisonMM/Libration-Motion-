#include <stdio.h>

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




int main() {

    /* my first program in C */
    printf("Hello, World! \n");

    float h = k(1, 2);

    printf("%.6f", h);

    return 0;
}