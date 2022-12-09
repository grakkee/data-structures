Homework3: driver.o event.o
	g++ -o Homework3 driver.o event.o

driver.0: driver.cpp arrayQueue.cpp priorityQueue.cpp event.cpp
	g++ -c driver.cpp

event.o: event.cpp event.h

event.o: event.cpp
	g++ -c event.cpp

clean:
	rm *-o
