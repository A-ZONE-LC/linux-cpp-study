.PHONY:all
all:detachthread mythread

detachthread:detachthread.c
		gcc -o $@ $^ -std=c99 -lpthread

mythread:mythread.c
		gcc -o $@ $^ -std=c99 -lpthread

.PHONY:clean
clean:
		rm -f mythread detachthread
