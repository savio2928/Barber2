#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include <iostream>
using namespace std;

//creates a customer NODE that stores the customer ID, Haircut time and a pointer that points to the next customer.
class Customer
{
    friend class CustomerList;

    public:

      Customer(int);

    private:
      int id,hairCutTime;
      Customer* next;
};



#endif // CUSTOMER_H_INCLUDED
