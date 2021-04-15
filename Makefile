all:	
	g++ -I /usr/include/ -o ./test.exe ./test.cpp -lgit2

clean:
	rm ./test.exe
