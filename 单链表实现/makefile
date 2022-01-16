mylist: Slist.o main.o
		gcc -o mylist Slist.o main.o
	
Slist.o:Slist.c
		gcc -c Slist.c -o Slist.o

main.o:main.c
		gcc -c main.c -o main.o

.PHONY:clean

clean:
	rm -rf mylist *.o
