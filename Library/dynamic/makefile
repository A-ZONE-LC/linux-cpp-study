libcal.so:add.o sub.o
		gcc -shared -o $@ $^

%.o:%.c
		gcc -fPIC -c $< -o $@

.PHONY:clean
clean:
		rm -rf *.o

.PHONY:output
output:
		mkdir -p dynamiclib/include
		mkdir -p dynamiclib/lib 
		cp -f *.h dynamiclib/include
		cp -f *.so dynamiclib/lib
