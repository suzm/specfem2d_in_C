#include "specfem2d.h"


int create_mass_matrix( const double Je, const int NGlob, double *mass_vector)
{
		// int order = 8;
	double gll_p[NSPEC+1];
	double gll_w[NSPEC+1];
	if (get_gll_points_weight(NSPEC, gll_p, gll_w)){
		int i=0;
		do
			printf("%e\t\t%e\n",gll_p[i], gll_w[i]);
		while(i++ < NSPEC );
	}
	else{
		return 0;
	}
	double mass_ele[(NSPEC+1)*(NSPEC+1)*2];
	memset(mass_ele, 0, (NSPEC+1)*(NSPEC+1)*2*sizeof(double));
	double mass_node;
	for(int i = 0; i< NSPEC+1; i++){
		printf("\n");
		for(int j = 0; j<=i; j++){
			mass_node = gll_w[i]*gll_w[j];
			mass_ele[i*(NSPEC+1)*2+j*2]= mass_node;
			mass_ele[i*(NSPEC+1)*2+j*2+1] = mass_node;
			if( i != j){
				mass_ele[j*(NSPEC+1)*2+i*2] = mass_node;
				mass_ele[j*(NSPEC+1)*2 +i*2+1] = mass_node;
			}

		}
			// printf("\t\t%e",gll_w[i]*gll_w[j]);
	}
	for(int i=0; i< NSPEC+1; i++){
		putchar('\n');
		for(int j=0; j< NSPEC +1; j++){
			printf("%f\t",mass_ele[i*(NSPEC+1)*2+j*2]);
		}
		putchar('\n');
		for(int j=0; j< NSPEC +1; j++){
			printf("%f\t",mass_ele[i*(NSPEC+1)*2+j*2+1]);
		} 
	}

	return 1;
};

