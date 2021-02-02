OBJS = main.o sds.o zskiplist.o
 
main: $(OBJS)
	gcc $(OBJS) -o main    
main.o: main.c
	gcc -c main.c -o main.o
sds.o: sds.c sds.h
	gcc -c sds.c -o sds.o
zskiplist.o: zskiplist.c zskiplist.h
	gcc -c zskiplist.c -o zskiplist.o
clean:
	rm -rf *.o main