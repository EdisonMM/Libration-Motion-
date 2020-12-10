outpout:compute_potential.o parameters.o diff_equations.o helper_subroutines.o rungeKutta.o potential.o gradient.o stable_orbits.o -lm
	gcc -o outpout compute_potential.o parameters.o diff_equations.o helper_subroutines.o rungeKutta.o potential.o gradient.o stable_orbits.o -lm

compute_potential.o:compute_potential.c parameters.c diff_equations.c helper_subroutines.c rungeKutta.c potential.c gradient.c stable_orbits.c
	gcc -c -pedantic -Wall -lm compute_potential.c parameters.c diff_equations.c helper_subroutines.c rungeKutta.c potential.c gradient.c  stable_orbits.c

parameters.o:parameters.c
	gcc -c -pednatic -Wall -lm parameters.c 

stable_orbits.o:stable_orbits.c
	gcc -c -pedantic -Wall -lm stable_orbits.c

diff_equations.o:diff_equations.c parameters.c
	gcc -c -pedantic -Wall -lm diff_equations.c parameters.c 

helper_subroutines.o:helper_subroutines.c 
	gcc -c -lm helper_subroutines.c 

rungeKutta.o:rungeKutta.c parameters.c diff_equations.c
	gcc -c -lm  rungeKutta.c parameters.c diff_equations.c 

potential.o:potential.c parameters.c diff_equations.c
	gcc -c -lm potential.c parameters.c diff_equations.c -lm

gradient.o:gradient.c parameters.c helper_subroutines.c potential.c
	gcc -c -lm parameters.c helper_subroutines.c potential.c -lm

clean:
	rm *.o outpout