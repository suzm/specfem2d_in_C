#include "specfem2d.h"

void stress(double *displ, double (*stress)[4], double *gll_p, double *gll_w, double (*deriva)[NSPEC+1]);

void create_stiff(double *stiff_res, double *displ)
{
	// partial_disp(double *displ);
	double gll_p[NSPEC+1], gll_w[NSPEC+1], deriva[NSPEC+1][NSPEC+1];
	get_gll_points_weight(NSPEC, gll_p, gll_w);
	lagrange_derivative(gll_p, deriva);
	double stress[NGLLX*NGLLZ][4];
	;
}

void stress(double *displ, double (*stress)[4], double *gll_p, double *gll_w, double (*deriva)[NSPEC+1])
{
	double first_deriv[NX*NZ][4];
	int node_index = 0;
	for (int i = 0; i < NGLLX; ++i)
	{
		for (int j = 0; j < NGLLZ; ++j)
		{
			first_deriv[node_index][0] = 0;
			for(int t = 0; t < NGLLX; ++t){
				first_deriv[node_index][0] += displ[i*NGLLX*2+t*2] * deriva[t][j]*JINV;
				// first_deriv[node_index][0] += displ[t*NGLLX*2+j*2]* deriva[t][j];
			}
			first_deriv[node_index][1] = 0;
			for(int t = 0; t < NGLLX; ++t){
				// first_deriv[node_index][0] += displ[i*NGLLX*2+t*2] * deriva[t][j]*JINV;
				first_deriv[node_index][1] += displ[t*NGLLX*2+j*2]* deriva[t][i]*JINV;
			}
			first_deriv[node_index][2] = 0;
			for(int t = 0; t < NGLLX; ++t){
				first_deriv[node_index][2] += displ[i*NGLLX*2+t*2+1] * deriva[t][j]*JINV;
				// first_deriv[node_index][0] += displ[t*NGLLX*2+j*2]* deriva[t][j];
			}
			first_deriv[node_index][3] = 0;
			for(int t = 0; t < NGLLX; ++t){
				// first_deriv[node_index][0] += displ[i*NGLLX*2+t*2] * deriva[t][j]*JINV;
				first_deriv[node_index][3] += displ[t*NGLLX*2+j*2+1]* deriva[t][i]*JINV;
			}

		}
	}
	
}