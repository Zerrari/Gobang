objects = main.o check.o scene.o movement.o

gobang : ${objects}
	g++ -o gobang ${objects}
	@echo "Complete!"
	@echo "./gobang to enjoy the game"

main.o : prog.h
check.o : 
scene.o :
movement.o : 

install:
	g++ -o demo main.o check.o scene.o movement.o

clean : 
	-rm gobang ${objects}
