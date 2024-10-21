all: run

run: main.o src/simulator.o
	g++ main.o src/simulator.o -o run

main.o:
	g++ -c main.cpp

simulator.o:
	g++ -c src/simulator.cpp

clean:
	rm -rf *.o src/*.o run