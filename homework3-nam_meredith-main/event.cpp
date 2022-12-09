#include "event.h"

Event::Event()
{
   arrivalTime = 0;
   transactionTime = 0;  
   eventType = ' ';
}

Event::Event(unsigned int arrTime, unsigned int transTime)
{
   arrivalTime = arrTime;
   transactionTime = transTime;
   eventType = 'A';
}

Event::Event(unsigned int arrTime, unsigned int transTime, char type)
{
   arrivalTime = arrTime;
   transactionTime = transTime;
   eventType = type;
}

unsigned int Event::getArrivalTime() const
{
   return arrivalTime;
}

unsigned int Event::getTransactionTime() const
{
   return transactionTime;
}

char Event::getEventType() const
{
   return eventType;
}

bool Event::operator>(const Event& other) const{
   if(arrivalTime > other.getArrivalTime()){
      return true;
   }
   else{
      return false;
   }
}
