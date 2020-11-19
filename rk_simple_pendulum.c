#include <stdio.h>
#include <math.h>

// I will use g/l = 1

float dudt(float t, float u, float theta)
{
    return -theta;
}

float dthetadt(float t, float u, float theta)
{
    return u;
}

float rk(float t0, float u0, float theta0, float t, float h)
{
    //n interations
    int n = (int) (t - t0)/h;

    //iterate
    float u=u0;
    float theta=theta0;

    for (int i=1; i<=n; i++)
    {
        //rk formula

        float k1 = h*dudt(t0, u, theta);
        float l1 = h*dthetadt(t0, u, theta);

        float k2 = h*dudt(t0 + 0.5*h, u + 0.5*k1, theta + 0.5*l1);
        float l2 = h*dthetadt(t0 + 0.5*h, u + 0.5*k1, theta + 0.5*l1);

        float k3 = h*dudt(t0 + 0.5*h, u + 0.5*k2, theta + 0.5*l2);
        float l3 = h*dthetadt(t0 + 0.5*h, u + 0.5*k2, theta + 0.5*l2);

        float k4 = h*dudt(t0 + h, u + k3, theta + l3);
        float l4 = h*dthetadt(t0 + h, u + k3, theta + l3);

        // update values

        u = u + (1.0/6.0) * (k1 + 2*k2 + 2*k3 + k4);
        theta = theta  + (1.0/6.0) * (l1 + 2*l2 + 2*l3 + l4);

        t0 = t0 + h;

    }

    return theta;
}

int main() 
{ 
    float t0 = 0, theta0 = 0, u0 = 1, t=2, h = 0.2; 
    printf("\nThe value of y at x is : %f", 
            rk(t0, u0, theta0, t, h)); 
    return 0; 
} 

