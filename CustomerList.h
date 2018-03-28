#ifndef CUSTOMERLIST_H_INCLUDED
#define CUSTOMERLIST_H_INCLUDED

#include "Customer.h"
//We create an object class CustomerList to mimic the queue at the barbers shop.
class CustomerList
{
    public:
        CustomerList(int);
        void addToTail(Customer* newOne);
        void printWaitingRoom();
        void CompletedHaircut();
        Customer* getHead(){return head;}
        int getID(){return head->id;}
        int getTime(){return head->hairCutTime;}
        int getCheck(){return first;}
        int setCheck(){first=0;}

    private:
        Customer* head;
        Customer* tail;
        int size, maxSeats,first,check;
};

#endif // CUSTOMERLIST_H_INCLUDED
