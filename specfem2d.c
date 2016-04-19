#include "specfem2d.h"

int main(int argc, char const *argv[])
{
	// const int NGLLX = NSPEC+1;
	// const int NGLLZ = NSPEC +1;
	const int NGlob = (NX*(NGLLX-1)+1)*(NZ*(NGLLZ-1)+1);
	const double Je = (double) XWIDTH/NX/2;
	printf("%e\n",Je );
	printf("Total node number is %d\n",NGlob);
	double u[NGlob*2];
	memset(u, 0, NGlob*2*sizeof(double));
	double mass_vector[NGlob *2];
	memset(mass_vector, 0, NGlob*2*sizeof(double));
	create_mass_matrix(Je, NGlob, mass_vector);
	double gll_p[NSPEC+1], gll_w[NSPEC+1], deriva[NSPEC+1][NSPEC+1];
	get_gll_points_weight(NSPEC, gll_p, gll_w);
	lagrange_derivative(gll_p, deriva);
	for (int i = 0; i <= NSPEC; ++i)
	{
		for (int j = 0; j <= NSPEC; ++j)
		{
			printf("%10f\t", deriva[i][j]);
		}
		printf("\n");
	}
	return 0;
}
