#include "parameters.h"
#include "helper_subroutines.h"
#include "potential.h"
#include <math.h>

void gradient(float m, float M, float R, float G, float x, float y, float p, float l, float h, float gd[])
{
    float x2, y2, phi, phix2, phiy2;

    x2 = x + h;
    y2 = y + h;

    float r = sqrt(pow(x,2) + pow(y,2));
    float rx2 = sqrt(pow(x2, 2) + pow(y, 2));
    float ry2 = sqrt(pow(y2,2) + pow(x,2));

    phi = atan(y/x);
    phix2 = atan(y/x2);
    phiy2 = atan(y2/x);

    float U = potential(m, M, R, G, r, phi, p, l);
    float Ux2 = potential(m, M, R, G, rx2, phix2, p, l);
    float Uy2 = potential(m, M, R, G, ry2, phiy2, p, l);

    float gdx = (Ux2 - U)/h;
    float gdy = (Uy2 - U)/h;

    gd[0] = gdx;
    gd[1] = gdy;
}

void compute_gradient(float m, float M, float R, float G, float xmin, float xmax, float ymin, float ymax, float p, float l, float h)
{
    int nx = (xmax - xmin)/h;
    int ny = (ymax - ymin)/h;
    float xarr[nx*ny];
    float yarr[ny*ny];

    float gdx[nx * ny];
    float gdy[nx * ny];

    int indx = 0;

    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            float x = xmin + i*h;
            float y = ymin + j*h;
            xarr[indx] = x;
            yarr[indx] = y;

            float gd[2];

            gradient(m, M, R, G, x, y, p, l, h, gd);

            gdx[indx] = gd[0];
            gdy[indx] = gd[1];

            indx++;
        }
    }

    write_gradient(nx*ny, xarr, yarr, gdx, gdy);
}
