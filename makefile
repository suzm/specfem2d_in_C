gll.o: gll.c specfem2d.h
	cc -c gll.c
main: gll.c specfem2d.h create_mass_matrix.c
	cc create_mass_matrix.c gll.o 