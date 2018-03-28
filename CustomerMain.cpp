#include <iostream>
using namespace std;

#include<thread>
#include "Random.h"
#include "CustomerFrequency.h"
#include "BarberStatus.h"

//we have a thread T1 responsible for creating more threads T2 to simulate the flow of customers
//we have a thread T3 imitating the barber which performs the 3 tasks sleeping, waking up and working.
//In case of compiler issue due to thread library.. kindly do the following... project-> build options-> select the C++11 compiler.
int main()
{
    int seats;

    cout<<"Enter Number of Seats"<< endl;
    cin>>seats;

    CustomerList * Cl1= new CustomerList(seats + 1);

    thread T3{BarberStatus,Cl1};
    thread T1{CallCustomerList,Cl1};

    T1.join();
    T3.join();

    return 0;
}

