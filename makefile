specfem2d: gll.o specfem2d.o create_mass_matrix.o
	cc -o specfem2d specfem2d.o gll.o create_mass_matrix.o
	./specfem2d

gll.o: gll.c specfem2d.h
	cc -c gll.c
specfem2d.o: specfem2d.h specfem2d.c
	cc -c specfem2d.c
create_mass_matrix.o: specfem2d.h create_mass_matrix.c
	gcc -c create_mass_matrix.c -std=c99
clean:
	rm *.o 