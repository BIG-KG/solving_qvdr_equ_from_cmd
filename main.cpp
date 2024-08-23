#include <stdio.h>
#include <math.h>
#include <stdlib.h>

enum num_of_solu {
  ZEROs = 0,
  ONEs = 1,
  TWOs = 2,
  INFs = -1,
};

int solve_sqrt(double a, double b, double c, double *otv1, double *otv2);

int main(int argc, char *argv[]){
	double a = atof((const char *) argv[1]);
	double b = atof((const char *) argv[2]);
	double c = atof((const char *) argv[3]);
	double *ans1 = (double *)malloc(sizeof(double));
	double *ans2 = (double *)malloc(sizeof(double));
	
	int num_of_equ = atoi((const char *) argv[1]);
	for(int i = 0; i < (argc - 1) / 3; i++){ 
		a = atof((const char *) argv[1 + i * 3]);
		b = atof((const char *) argv[2 + i * 3]);
		c = atof((const char *) argv[3 + i * 3]);
		
		solve_sqrt(a, b, c, ans1, ans2);
		printf("a = %lf b = %lf c = %lf ans1 = %lf, ans2 = %lf\n ", a, b, c, *ans1, *ans2);

	}
}



int solve_sqrt(double a, double b, double c, double *otv1, double *otv2){
    double D = 0;
    D = (b * b) - (4 * a * c);

    if (D == 0)
    {
        *otv1 = (-b) / (2 * a);
        return ONEs;
    }
    if (D < 0)
        return ZEROs;


    D = sqrt(D);
    *otv1 = (-b - D) / (2 * a);
    *otv2 = (-b + D) / (2 * a);
    return TWOs;
}