#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
using namespace std;

class Event
{
private:
   char eventType;
   unsigned int arrivalTime;
   unsigned int transactionTime;

public:
   Event();
   Event(unsigned int arrTime, unsigned int transTime);
   Event(unsigned int arrTime, unsigned int transTime, char type);
  
   unsigned int getArrivalTime() const;
   unsigned int getTransactionTime() const;
   char getEventType() const;

   bool operator >(const Event& other) const; 
};
#endif