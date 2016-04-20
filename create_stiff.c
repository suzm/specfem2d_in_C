#include "specfem2d.h"

void get_stress(double *displ, double (*stress)[4], double (*deriva)[NSPEC+1]);

void build_stiff(double gll_w, double *stiff_res, double (*stress)[4], double (*deriva)[NSPEC+1]);

void create_stiff(double *stiff_res, double *displ)
{
	// partial_disp(double *displ);
	double gll_p[NSPEC+1], gll_w[NSPEC+1], deriva[NSPEC+1][NSPEC+1];
	get_gll_points_weight(NSPEC, gll_p, gll_w);
	lagrange_derivative(gll_p, deriva);
	double stress[NGLLX*NGLLZ][4];
	get_stress(displ, stress, deriva);
}

void get_stress(double *displ, double (*stress)[4],  double (*deriva)[NSPEC+1])
{
	double first_deriv[NX*NZ][4];
	int node_index = 0;
	for (int i = 0; i < NGLLZ; ++i)
	{
		for (int j = 0; j < NGLLX; ++j)
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
			++ node_index;
		}
	}

	node_index = 0;
	for (int rei = 0; rei < NGLLZ; ++rei)
	{
		for (int cei = 0; cei < NGLLX; ++cei)
		{
			stress[node_index][0] = (LAMBDA+2*MU)*first_deriv[node_index][0] + LAMBDA * first_deriv[node_index][3];
			stress[node_index][1] = MU * (first_deriv[node_index][1] + first_deriv[node_index][2]);
			stress[node_index][2] = stress[node_index][1];
			stress[node_index][3] = (LAMBDA+2*MU)*first_deriv[node_index][3] + LAMBDA * first_deriv[node_index][0];
			++ node_index;
		}
	}
}

void build_stiff(double gll_w, double *stiff_res, double (*stress)[4], double (*deriva)[NSPEC+1])
{
	;
}