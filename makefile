a.out: main.o convertation/convertation.o
	cc main.o convertation/convertation.o -o a.out	

main.o: main.c convertation/convertation.h
	cc -c main.c -o main.o 

convertation.o : convertation/convertation.c convertation/convertation.h
	cc -c convertation/convertation.c -o convertation/convertation.o

clean:
	rm -f *.o
	rm -f convertation/*.o