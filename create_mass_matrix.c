#include "specfem2d.h"

#define N 4
#define rho 30000
#define J 2

int create_mass_matrix(void)
{
		// int order = 8;
	double gll_p[N+1];
	double gll_w[N+1];
	if (get_gll_points_weight(N, gll_p, gll_w)){
		int i=0;
		do
			printf("%e\t\t%e\n",gll_p[i], gll_w[i]);
		while(i++ < N );
	}
	return 0;
};

int main(int argc, char const *argv[])
{
	create_mass_matrix();
	return 0;
}