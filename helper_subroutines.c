#include <stdio.h>
#include <stdlib.h>

void write_results(int N, float t[], float r[], float phi[], float p[], float l[], float x[], float y[], float U[]){


    FILE * outfile = fopen("motion_results.csv", "w");

    fprintf(outfile, "t,r,phi,p,l,x,y,U\n");

    for (int i = 0; i < N; i++)
    {
        fprintf(outfile, "%E,%E,%E,%E,%E,%E,%E,%E\n", t[i], r[i], phi[i], p[i], l[i], x[i], y[i], U[i]);
        //printf("%f", t[i]);
    }


    fclose(outfile);

    return;
}

//testing

/*
int main(){

    int N = 1;

    float t[1] = {1.0};
    float r[1] = {2.0};
    float phi[1] = {3.0};
    float p[1] = {4.0};
    float l[1] = {5.0};
    float U[1] = {6.0};
    float x[1] = {3.5};
    float y[1] = {5.5};

    write_results(N, t, r, phi, p, l, U, x, y);

    return 0;
}
*/
