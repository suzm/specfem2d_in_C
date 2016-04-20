#include "specfem2d.h"
// #include <math.h>
// #define M_PI 3.1415926
void ricker(int nt, double  dt, double fM, double *source)
{
	// double fM = 100;
	double temp = 0;
	for (int i = 0; i < nt; ++i)
	{
		temp = M_PI*fM*dt*(i-100);
		temp *= temp;
		source[i] = (1-2*temp)*exp(-temp);	
	}
}

// int main(int argc, char const *argv[])
// {
// 	int nt = 1000; 
// 	double fM = 20; 
// 	double dt=0.001;
// 	double source[nt];
// 	ricker(nt, dt, fM, source);
// 	FILE *fp = fopen("source.gnu","w");
// 	for (int i = 0; i < nt; ++i)
// 	{
// 		fprintf(fp, "%d\t\t%.10f\n",i, source[i]);
// 	}
// 	fclose(fp);
// 	return 0;
// }