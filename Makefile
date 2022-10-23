DEPS = afd.h

afdtool: main.o le_afd.o to_graphviz.o reconhecer.o utils.o
	gcc main.o le_afd.o to_graphviz.o reconhecer.o utils.o -o afdtool

main.o: main.c
	gcc -c main.c

le_afd.o: le_afd.c le_afd.h
	gcc -c le_afd.c

to_graphviz.o: to_graphviz.c to_graphviz.h
	gcc -c to_graphviz.c

reconhecer.o: reconhecer.c reconhecer.h
	gcc -c reconhecer.c

utils.o: utils.c utils.h
	gcc -c utils.c

clean:
	rm *.o afdtool
