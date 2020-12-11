#include <stdio.h>
#include <stdlib.h>


void write_results(int N, float t[], float x[], float y[], char* fileName){

    FILE * outfile = fopen(fileName, "w");

    fprintf(outfile, "t,r,phi,p,l,x,y\n");

    for (int i = 0; i < N; i++)
    {
        fprintf(outfile, "%E,%E,%E\n", t[i], x[i], y[i]);
        //printf("%f", t[i]);
    }


    fclose(outfile);

    return;
}

void write_gradient(int N, float x[], float y[], float gdx[], float gdy[]){


    FILE * outfile = fopen("gradient_results.csv", "w");

    fprintf(outfile, "x,y,d/dx,d/dy\n");

    for (int i = 0; i < N; i++)
    {
        fprintf(outfile, "%E,%E,%E,%E\n", x[i], y[i], gdx[i], gdy[i]);
    }


    fclose(outfile);

    return;
}

void write_parameters(int N, float t0, float tmax, float r0, float phi0, float p0, float l0, float m, float M, float R, float G, float h)
{
    FILE * outfile = fopen("parameters.txt", "w");
    fprintf(outfile, "%d\n", N);
    fprintf(outfile, "%E\n", m);
    fprintf(outfile, "%E\n", M);
    fprintf(outfile, "%E\n", R);
    fprintf(outfile, "%E\n", h);
    fprintf(outfile, "%E\n", t0);
    fprintf(outfile, "%E\n", tmax);
    fprintf(outfile, "%E\n", r0);
    fprintf(outfile, "%E\n", phi0);
    fprintf(outfile, "%E\n", p0);
    fprintf(outfile, "%E\n", l0);
    fprintf(outfile, "%E\n", G);
}


