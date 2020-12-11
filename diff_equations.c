#include <math.h>
#include "parameters.h"

float S(float m, float M, float R, float r, float phi, float p, float l, float G){

    float tmp = pow(r*sin(phi), 2) + pow((r*cos(phi) + lamda(m, M) * R), 2);

    return pow(tmp, 0.5);
}

float s(float m, float M, float R, float r, float phi, float p, float l, float G){

    float tmp = pow(r*sin(phi),2) + pow(r*cos(phi) - (1 - lamda(m, M))*R ,2);

    return pow(tmp, 0.5);
}


float rdot(float t, float m, float M, float R, float r, float phi, float p, float l, float G){

    return p;
}

float phidot(float t, float m, float M, float R, float r, float phi, float p, float l, float G){

    return (l/pow(r,2)) - omega(m, M, R, G);
}

float pdot(float t, float m, float M, float R, float r, float phi, float p, float l, float G){

    float a = pow(l,2)/pow(r,3);
    
    float b = pow( omega(m, M, R, G), 2) * pow(R, 3) * (1 - lamda(m, M)) * (r + lamda(m, M) * R * cos(phi)) / pow(S(m, M, R, r, phi, p, l, G), 3);

    float c = pow(omega(m, M, R, G), 2)*pow(R, 3) * lamda(m, M) * (r - (1 - lamda(m, M))*R*cos(phi))/pow(s(m, M, R, r, phi, p, l, G), 3);

    return (a - b - c);
}

float ldot(float t, float m, float M, float R, float r, float phi, float p, float l, float G){

    float S_val = S(m, M, R, r, phi, p, l, G);
    float s_val = s(m, M, R, r, phi, p, l, G);

    return pow(omega(m, M, R, G), 2)*pow(R,4)*lamda(m, M)*(1 - lamda(m, M))*(pow(S_val, -3) - pow(s_val, -3))*r*sin(phi);

}

/*

Testing

int main(){

    float m = 1, M = 1, R = 1, G = 1;

    printf("%f", lamda(m, M));

    return 0;
}

*/