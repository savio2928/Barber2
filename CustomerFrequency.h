#ifndef CUSTOMERFREQUENCY_H_INCLUDED
#define CUSTOMERFREQUENCY_H_INCLUDED
#include<thread>
#include "CustomerList.h"

using namespace std;


void thread2(CustomerList * C3,int & counter1);
//with is function we recursively call more threads to simulate the flow of customers.
void CallCustomerList (CustomerList * C2)
{
    int counter=1;
    while(true)
    {
     thread T2{thread2,C2,ref(counter)};
     this_thread::sleep_for(chrono::seconds(3));
     counter ++;
     T2.join();
    }
}
//Here we create a single customers and link then to the que.
void thread2(CustomerList * C3,int & counter1)
{
    Customer* a= new Customer(counter1);
    C3->addToTail(a);
}


#endif // CUSTOMERFREQUENCY_H_INCLUDED
