run: BST
	./BST

BST.o: BST.cpp
	g++ -c BST.cpp

BST: BST.o
	g++ BST.o -o BST

clean:
	rm -f *.o
	rm BST
