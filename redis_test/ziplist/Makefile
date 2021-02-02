OBJS = main.o endianconv.o sha256.o ziplist.o util.o
 
main: $(OBJS)
	gcc $(OBJS) -o main    
main.o: main.c
	gcc -c main.c -o main.o
endianconv.o: endianconv.c endianconv.h
	gcc -c endianconv.c -o endianconv.o
sha256.o: sha256.c sha256.h
	gcc -c sha256.c -o sha256.o
ziplist.o: ziplist.c ziplist.h
	gcc -c ziplist.c -o ziplist.o
util.o: util.c util.h
	gcc -c util.c -o util.o
clean:
	rm -rf *.o main