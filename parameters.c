#include <stdio.h>

float k(float m, float M)
{
    return m/M;
}

int main() {

    /* my first program in C */
    printf("Hello, World! \n");

    float h = k(1, 2);

    printf("%.6f", h);

    return 0;
}