OBJS = main.o ae.o ae_kqueue.o
 
main: $(OBJS)
	gcc $(OBJS) -o main    
main.o: main.c
	gcc -c main.c -o main.o
ae.o: ae.c ae.h
	gcc -c ae.c -o ae.o
ae_kqueue.o: ae_kqueue.c
	gcc -c ae_kqueue.c -o ae_kqueue.o
clean:
	rm -rf *.o main