#ifndef BARBERSTATUS_H_INCLUDED
#define BARBERSTATUS_H_INCLUDED
#include<thread>

#include "Customer.h"



//here we look at the 3 possible tasks of the barber: sleeping, waking up and working
void BarberStatus (CustomerList * C4)
{
    cout<<"Barber sleeping"<<endl;   //initial position of the barber
    C4->printWaitingRoom();
    while (true)
    {
        Customer* status= C4->getHead();
        int test=C4->getCheck();

           if (status==NULL && test==1)   //SLEEPING: here we checks if the head pointer is NULL (indicates no customer)and our test flag(test=1) indicates if we have printed this information if not we print the desired information and change the flag.
           {
               cout<<"Barber sleeping"<<endl;
               C4->printWaitingRoom();
               C4->setCheck();
           }

           else if (test==3)   //WAKING UP: test= 3 indicates that a new customer has arrived. We print the desired activities then make the thread sleep for the desired time since there is no activity for the barber when he is cutting hair and after he has completed we delete the thread by calling CompletedHaircut.
           {
                cout<<"Barber Waking up "<< endl;
                C4->setCheck();
                cout<<"Barber cutting the hair of customer "<<C4->getID()<<endl;
                C4->printWaitingRoom();
                int a =C4->getTime();
                this_thread::sleep_for(chrono::seconds(a));
                C4->CompletedHaircut();
            }

            else if(status !=NULL)  //WORKING: If there is more than one customer we just display the required information. Then make the thread sleep for the time the time it takes for that customers haircut and once it wakes up we delete the customer by calling CompletedHaircut.
            {
               cout<<"Barber cutting the hair of customer "<<C4->getID()<<endl;
               C4->printWaitingRoom();
               int a =C4->getTime();
               this_thread::sleep_for(chrono::seconds(a));
               C4->CompletedHaircut();
            }
    }
}





#endif // BARBERSTATUS_H_INCLUDED
