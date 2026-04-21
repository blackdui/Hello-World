main: module_student.o main.o
	g++ -std=c++20 -fmodules-ts module_student.o main.o -o main

module_student.o:
	g++ -std=c++20 -fmodules-ts -c module_student.ppm -o module_student.o

main.o:
	g++ -std=c++20 -c main.cpp -o main.o

