libcal.a:add.o sub.o
		ar -rc $@ $^

%.o:%.c
		gcc -c $<

.PHONY:clean
clean:
		rm -f *.a *.o 

.PHONY:output
output:
		mkdir -p staticlib/lib 
		mkdir -p staticlib/include
		cp *.h staticlib/include
		cp *.a staticlib/lib
