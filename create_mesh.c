#include <stdio.h>
#define region_width 100
#define region_depth 100
#define col_ele_num 200
#define row_ele_num 200
int main()
{
	char mesh_name[] = "specfem2d_mesh";
	FILE *fp = fopen(mesh_name, "w");
	const int nod_wid_num = col_ele_num + 1;
	const int nod_dep_num = row_ele_num + 1;
	
	const	double ele_wid_average = (double)region_depth / col_ele_num;
	const double ele_dep_average = (double)region_depth / row_ele_num;
	double nod_x = 0;
	double nod_y = 0;
	//char line_temp[30], *ptr;
	int nod_index = 1;
	int nod_mat[201][201];
	fprintf(fp, "nod location:\n");
	for (int i = 0; i < nod_wid_num; i++) {
		nod_y = 0;
		for (int j = 0; j < nod_dep_num; j++) {
			fprintf(fp, "%i\t\t\t%e\t\t\t%e\n",nod_index, nod_x, nod_y);
			
			nod_mat[i][j] = nod_index;
			nod_index += 1;
			nod_y -= ele_dep_average;
		}
		nod_x += ele_wid_average;
	}
	fprintf(fp, "element corrdinate\n");
	int lu, ld, rd, ru;
	int ele_index = 1;
	for (int i = 0; i < col_ele_num; i++) {
		for (int j = 0; j < row_ele_num; j++) {
			lu = nod_mat[i][j];
			ld = nod_mat[i + 1][j];
			rd = nod_mat[i + 1][j + 1];
			ru = nod_mat[i][j + 1];
			fprintf(fp, "%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",ele_index, lu, ld, rd, ru);
			ele_index += 1;
		}
	}
	//printf("Test\n");
	return 0;
}