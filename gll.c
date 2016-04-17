#include <stdio.h>
#include <string.h>
int  get_gll_points_weight(int order, double *gll_p, double *gll_w)
{
	
		

	double gll_loc_4[5] = {-1, -0.6546536707, 0, 0.6546536707, 1};
	double gll_loc_5[6] = {-1, -0.7650553239, -0.2852315164, 0.2852315164, 0.7650553239,1};
    double gll_loc_6[7] = {-1, -0.8302238962, -0.4688487934, 0, 0.4688487934, 0.8302238962, 1};
	double gll_loc_7[8] = {-1, -0.8717401485, -0.5917001814, -0.2092992179, 0.2092992179, 0.5917001814, 0.8717401485, 1};
	double *gll_loc[4]={gll_loc_4,gll_loc_5, gll_loc_6, gll_loc_7};

	double gll_wgt_4[5] = {0.1, 0.5444444444, 0.7111111111, 0.5444444444, 0.1};
	double gll_wgt_5[6] = {0.0666666666, 0.3784749562, 0.5548583770, 0.5548583770, 0.3784749562, 0.0666666666};
	double gll_wgt_6[7] = {0.0476190476, 0.2768260473, 0.4317453812, 0.4876190476, 0.4317453812, 0.2768260473, 0.0476190476};
	double gll_wgt_7[8] = {0.0357142857, 0.2107042271, 0.3411226924, 0.4124587946, 0.4124587946, 0.3411226924, 0.2107042271, 0.0357142857};
	double *gll_wgt[4]={gll_wgt_4, gll_wgt_5, gll_wgt_6, gll_wgt_7};
	if (order < 4 || order > 7){
		printf("Order %d is too large or small. Choose an proper instead.\n", order);
		return 0;
	}
	memcpy(gll_p, gll_loc[order-4], sizeof(double)*(order+1));
	memcpy(gll_w, gll_wgt[order-4], sizeof(double)*(order+1));
	return 1;
	
}
// int *gll_weights(int order)
int main(int argc, char const *argv[])
{
	int order = 8;
	double gll_p[order+1];
	double gll_w[order+1];
	if (get_gll_points_weight(order, gll_p, gll_w)){
		int i=0;
		do
			printf("%e\t\t%e\n",gll_p[i], gll_w[i]);
		while(i++ < order );
	}
	return 0;
}