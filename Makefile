.cpp.o:	$*.h
	g++	-c $*.cpp

all:	main

main:  main.o cNo.o cPoint.o  cQuad.o  cColor.o quadTree.o
	g++ -o $@ $^

clean:
	rm  *.o main
