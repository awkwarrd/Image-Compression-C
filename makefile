a.out: main.o convertation/convertation.o binary_tree/binary_tree.o
	cc main.o convertation/convertation.o binary_tree/binary_tree.o -o a.out	

main.o: main.c convertation/convertation.h binary_tree/binary_tree.h
	cc -c main.c -o main.o 

convertation.o : convertation/convertation.c convertation/convertation.h
	cc -c convertation/convertation.c -o convertation/convertation.o

binary_tree.o : binary_tree/binary_tree.c binary_tree/binary_tree.h
	cc -c binary_tree/binary_tree.c -o binary_tree/binary_tree.o

clean:
	rm -f *.o
	rm -f convertation/*.o
	rm -f binary_tree/*.o