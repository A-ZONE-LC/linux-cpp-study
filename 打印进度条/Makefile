mypro:func.o main.o
		gcc -o mypro func.c main.c

func.o:func.c
		gcc -c func.c -o func.o

main.o:main.c
		gcc -c main.c -o main.o

.PHONY:clean
clean:
		rm -rf ./*.o mypro
