#include <stdio.h>
#include <string.h>
#include <math.h>

#define NSPEC 4
#define RHO 3E10
#define XWIDTH 100
#define ZDEPTH 150 
#define NX 40
#define NZ 60
#define NGLLX 5
#define NGLLZ 5

int  get_gll_points_weight(int order, double *gll_p, double *gll_w);
double legendre(double x);
int create_mass_matrix( const double Je, const int NGlob, double *mass_vector);
int ele_to_node(int rei, int cei, int *node_list );
void lagrange_derivative(double *gll_p, double *lag_deriva);