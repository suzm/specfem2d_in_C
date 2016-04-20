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
#define J 2
#define JINV 0.5
#define LAMBDA 38
#define MU 32

int  get_gll_points_weight(int order, double *gll_p, double *gll_w);
double legendre(double x);
int create_mass( const double Je, const int NGlob, double *mass_vector);
void create_stiff(double *stiff_res, double *displ);
int ele_to_node(int rei, int cei, int *node_list );
void lagrange_derivative(double *gll_p, double (*lag_deriva)[NSPEC+1]);
void copy_by_list(double *origin_l, double *target_l, int *node_l, int length);