Homework4: driver.o bubble.o selection.o quick.o sort.o
	g++ -o Homework4 driver.o bubble.o selection.o quick.o sort.o

driver.o: driver.cpp bubble.h selection.h quick.h
	g++ -c driver.cpp

bubble.o: bubble.cpp bubble.h sort.h
	g++ -c bubble.cpp

selection.o: selection.cpp selection.h sort.h
	g++ -c selection.cpp

quick.o: quick.cpp quick.h sort.h
	g++ -c quick.cpp

sort.o: sort.cpp sort.h
	g++ -c sort.cpp