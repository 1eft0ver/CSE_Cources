all: main main2 clean

main: stack.o main.o
	g++ -ggdb -o main stack.o main.o

main2: stack.o main2.o
	g++ -ggdb -o main2 stack.o main2.o

stack.o: stack.c
	g++ -ggdb -c stack.c

main.o: main.c
	g++ -ggdb -c main.c

main2.o: main2.c
	g++ -ggdb -c main2.c

dep:
	@echo "Do nothing"

clean:
	rm -f *.o

