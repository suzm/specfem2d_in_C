specfem2d: gll.o specfem2d.o create_mass.o create_stiff.o utils.o source.o 
	gcc -o specfem2d  specfem2d.o gll.o create_mass.o create_stiff.o utils.o  source.o -std=c99 -lm 
	./specfem2d
utils.o: specfem2d.h utils.c
	gcc -c utils.c -std=c99
gll.o: gll.c specfem2d.h
	gcc -c gll.c -std=c99
specfem2d.o: specfem2d.h specfem2d.c
	gcc -c specfem2d.c -std=c99
create_mass.o: specfem2d.h create_mass.c
	gcc -c create_mass.c -std=c99
create_stiff.o: specfem2d.h create_stiff.c
	gcc -c create_stiff.c -std=c99
source.o: specfem2d.h source.c
	gcc -c source.c 

clean:
	rm *.o 