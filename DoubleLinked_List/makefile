outfile:main.o List.o
		gcc main.o List.o -o outfile 

main.o:main.c
		gcc -c main.c -o main.o

List.o:List.c
		gcc -c List.c -o List.o

.PHONY:clean
clean:
		rm -rf outfile *.o
