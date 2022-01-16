SeqTest:main.o Seqlist.o
		gcc -o SeqTest main.o Seqlist.o

main.o:main.c
		gcc -c main.c -o main.o

Seqlist.o:Seqlist.c
		gcc -c Seqlist.c -o Seqlist.o

.PHONY:clean

clean:
		rm -rf *.o SeqTest
