#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o and student.o to executable main
main: main.o student.o toeflScore.o sfuSort.o
	g++ -g -o main main.o student.o toeflScore.o sfuSort.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp

#compile the student.cpp to student.o
student.o: student.cpp
	g++ -g -c student.cpp
toeflScore.o: toeflScore.cpp
	g++ -g -c toeflScore.cpp
sfuSort.o: sfuSort.cpp
	g++ -g -c sfuSort.cpp

#remove built files
clean:
	rm -rf main main.o student.o toeflScore.o sfuSort.o *~
