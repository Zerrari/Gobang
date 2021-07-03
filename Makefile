demo : main.o check.o scene.o movement.o
	g++ -o demo main.o check.o scene.o movement.o

main.o : main.cpp prog.h
	g++ -c main.cpp prog.h

check.o : check.cpp
	g++ -c check.cpp

scene.o : scene.cpp
	g++ -c scene.cpp

movement.o : movement.cpp
	g++ -c movement.cpp

clean : 
	rm demo main.o check.o scene.o movement.o
