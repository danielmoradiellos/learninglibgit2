all:	
	g++ -I /usr/include/ -o ./test.exe ./test.cpp -lgit2
	gcc -I /usr/include/ -o ./test0.exe ./test0.c -lgit2

clean:
	rm ./*.exe
