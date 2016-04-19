#include "specfem2d.h"

int ele_to_node(int rei,int cei, int *node_list )
{
	int lu_inx =  rei*(NGLLZ-1)*(NX*(NGLLX-1)+1)*2 + cei*(NGLLX-1)*2;
	int tmp_idx = 0;
	for (int i = 0; i < NGLLZ; ++i){
		for (int j = 0; j < NGLLX; ++j)
		{
			node_list[tmp_idx++] = lu_inx + j*2;
			node_list[tmp_idx++] = lu_inx + j*2 + 1;
		}
		lu_inx += (NX*(NGLLX-1)+1)*2;
	}
	return 1;
}

void copy_by_list(double *origin_l, double *target_l, int *node_l, int length)
{
	for (int i = 0; i < length; ++i)
		target_l[i] = origin_l[node_l[i]];
}