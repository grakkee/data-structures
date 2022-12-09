//Authors: Grace Meredith & Yoonsung Nam
//CS 302 - Homework 3
//Date: 3/14/2021
//Purpose: Utilize the concept of priority queue and array queue alongside the event class in order to create a simulation

//Grace's Contribution: driver.cpp, event class
//Yoonsung's Contribution: queue class, priority queue class, makefile

#include"arrayQueue.h"
#include"priorityQueue.h"
#include"event.h"

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

#define MIN_ARGS 2

void simulate(string filename);
int main(int argc, char* argv[]){
    if(argc < MIN_ARGS){
        cout << "Correct Usage: " << endl << "./Homework3 filename" << endl;
        return 0;
    }

    string userFile = argv[1];
    simulate(userFile);
    return 0;
}

void simulate(string filename){
   unsigned int eventsCount = 0;
   unsigned int totalArrivalTime = 0;
   unsigned int totalDepartureTime = 0;
   unsigned int totalProcessingTime = 0;
   double averageWaitingTime;

   ifstream dataFile;
   dataFile.open(filename);

   if (dataFile.fail())
   {
       cout << filename << " file cannot be opened!" << endl;
       cout << endl;
       system("pause");
       exit(EXIT_FAILURE);
   }

   ArrayQueue<Event> bankQueue;
   PriorityQueue<Event> eventListPQueue;

   bool tellerAvailable = true;
  
   int a, t;
   while (dataFile >> a >> t)
   {
       Event newArrivalEvent(a, t);
       eventListPQueue.enqueue(newArrivalEvent);
   }
   dataFile.close();
  
   cout << "Simulation Begins" << endl;

   while (!eventListPQueue.isEmpty())
   {
       Event newEvent = eventListPQueue.peekFront();

       unsigned int currentTime = newEvent.getArrivalTime();
       if (newEvent.getEventType() == 'A')
       {
           eventListPQueue.dequeue();
           Event customer = newEvent;
           if (bankQueue.isEmpty() && tellerAvailable)
           {
               unsigned int departureTime = currentTime + newEvent.getTransactionTime();
               Event newDepartureEvent(departureTime, 0, 'D');
               eventListPQueue.enqueue(newDepartureEvent);
               tellerAvailable = false;
           }
           else
           {
               bankQueue.enqueue(customer);
           }

           cout << "Processing an arrival event at time:\t" << customer.getArrivalTime() << endl;          
           eventsCount++;
           totalArrivalTime += customer.getArrivalTime();
           totalProcessingTime += customer.getTransactionTime();
       }
       else
       {
           eventListPQueue.dequeue();

           if (!bankQueue.isEmpty())
           {
               Event customer = bankQueue.peekFront();
               bankQueue.dequeue();
               int departureTime = currentTime + customer.getTransactionTime();              
               Event newDepartureEvent(departureTime, 0, 'D');
               eventListPQueue.enqueue(newDepartureEvent);
           }
           else
           {
               tellerAvailable = true;
           }

           cout << "Processing a departure event at time:\t" << currentTime << endl;
           totalDepartureTime += currentTime;
       }
   }

   averageWaitingTime = (totalDepartureTime - totalProcessingTime - totalArrivalTime) / eventsCount;
  
   cout << "Simulation Ends" << endl << endl;
   cout << "Final Statistics:" << endl << endl;
   cout << "\tTotal number of people processed: " << eventsCount << endl;
   cout << "\tAverage amount of time spent waiting: " << averageWaitingTime << endl;   
}
