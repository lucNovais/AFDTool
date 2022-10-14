DEPS = afd.h

afdtool: main.o le_afd.o to_graphviz.o
	g++ main.o le_afd.o to_graphviz.o -o afdtool

main.o: main.c
	g++ -c main.c

le_afd.o: le_afd.c le_afd.h
	g++ -c le_afd.c

to_graphviz.o: to_graphviz.c to_graphviz.h
	g++ -c to_graphviz.c

clean:
	rm *.o afdtool
