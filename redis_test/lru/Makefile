OBJS = main.o adlist.o
 
main: $(OBJS)
	g++ $(OBJS) -o main    
main.o: main.cpp
	g++ -c main.cpp -o main.o
adlist.o: adlist.c adlist.h
	gcc -c adlist.c -o adlist.o
clean:
	rm -rf *.o main