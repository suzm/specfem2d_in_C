specfem2d: gll.o specfem2d.o create_mass_matrix.o utils.o
	gcc -o specfem2d specfem2d.o gll.o create_mass_matrix.o utils.o -std=c99
	./specfem2d
utils.o: specfem2d.h utils.c
	gcc -c utils.c -std=c99
gll.o: gll.c specfem2d.h
	gcc -c gll.c -std=c99
specfem2d.o: specfem2d.h specfem2d.c
	gcc -c specfem2d.c -std=c99
create_mass_matrix.o: specfem2d.h create_mass_matrix.c
	gcc -c create_mass_matrix.c -std=c99
clean:
	rm *.o 