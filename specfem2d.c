#include "specfem2d.h"

int main(int argc, char const *argv[])
{
	// const int NGLLX = NSPEC+1;
	// const int NGLLZ = NSPEC +1;
	const int NGlob = (NX*(NGLLX-1)+1)*(NZ*(NGLLZ-1)+1);
	const double Je = (double) XWIDTH/NX/2;

	double  vp = sqrt((LAMBDA+2*MU)/RHO);
	double  dx = XWIDTH/NX;
	double 	dt = dx*0.9/vp;
	printf("%e\n",Je );
	printf("Total node number is %d\n",NGlob);

	// Create displacement vector
	double u[NGlob*2];
	memset(u, 0, NGlob*2*sizeof(double));

	double source_f[NGlob*2];
	memset(source_f, 0, NGlob*2*sizeof(double));	
	// Create mass matrix
	double mass_vector[NGlob *2 ];
	memset(mass_vector, 0, NGlob*2*sizeof(double));
	create_mass(Je, NGlob, mass_vector);

	// The following codes are used to calculate the product of stiffness matrix and displacement vector
	double stif_vector[NGlob * 2];
	memset(stif_vector, 0, NGlob*2*sizeof(double));

	double vel[NGlob * 2];
	memset(vel, 0, NGlob*2*sizeof(double));

	double ele_stif_res[NGLLX*NGLLZ*2];
	memset(ele_stif_res, 0, 2*NGLLX*NGLLZ*sizeof(double));

	double ele_displ[NGLLX*NGLLZ*2];
	memset(ele_displ, 0, 2*NGLLX*NGLLZ*sizeof(double));

	int ele_nodes[NGLLX*NGLLZ*2];
	memset(ele_nodes, 0, 2*NGLLX*NGLLZ*sizeof(int));



	for(int time_n = 0; time_n < 1000; time_n++){
		// Start time loop 
		printf("%d\n",time_n );
		for (int i = 0; i < 2*NGlob; ++i){
			u[i] = dt*vel[i] + stif_vector[i]*dt*dt/2;
			vel[i] += dt*stif_vector[i]/2;
		}

		for (int rei = 0; rei < NX; ++rei)
		{
			for(int cei = 0; cei < NZ; ++cei){
				memset(ele_nodes, 0, 2*NGLLX*NGLLZ*sizeof(int));
				ele_to_node(rei, cei, ele_nodes);
				copy_by_list(u, ele_displ, ele_nodes, NGLLX*NGLLZ);
				create_stiff(ele_stif_res, ele_displ);
				for (int i = 0; i < 2*NGLLX*NGLLZ; ++i)
				{
					stif_vector[ele_nodes[i]] += ele_stif_res[i];
				}

			}

		}
		add_source(stif_vector, dt, time_n);
		for(int i=0 ; i < 2*NGlob; i++)
			stif_vector[i] /= mass_vector[i];

		for (int i = 0; i < 2*NGlob; ++i)
			vel[i] += dt/2*stif_vector[i];



	}


	


	//The following codes are used to test lagrange first order derivative.
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
