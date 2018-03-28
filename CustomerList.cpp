#include "CustomerList.h"
#include "Customer.h"

//defined 2 extra variables first and check. First is used to monitor if someone new comes in and wakes up the barber. Check is used to monitor if a customer has left the barbers shop without getting a haircut(display purpose).

using namespace std;
CustomerList::CustomerList(int n): maxSeats(n),head(NULL), tail(NULL), size(0),first(0),check(0)
{}

// addToTail is responsible for adding new customers to the queue.
void CustomerList::addToTail(Customer* newOne)   // NEW ONE TERMINATES AFTER CREATION
{

  if(head != NULL && size <= maxSeats)
    {
         tail->next = newOne;
         tail=newOne;
         size++;
         first = 0;
    }

    else if(head == NULL)
    {
         head = newOne;
         tail = newOne;
         size++;
         first = 3;
    }


   else
   {
        check = newOne->id;
   }
}
// this prints the Waiting room Que and also the customers that left without getting their hair cut.
void CustomerList::printWaitingRoom()
{
    Customer*tp=head;
    cout<<"Waiting Room: ";
    if(tp)
        {
        tp=tp->next;
        while(tp!=0)
            {
                cout<<tp->id<<" ";
                tp=tp->next;
            }
        }
    cout<<" "<<endl;

    if(check)
        {
            cout<<"Customer " << check << " leaving"<<endl;
            check=0;
        }
    cout<<" "<<endl;
}
//This is used to delete a customer. This indicates the customer has completed his haircut.
void CustomerList::CompletedHaircut()
{
 if (head==tail)   //If there is only one customer. we reassign the pointers to NULL and create a flag indicator first to point that its time for the barber to sleep.
    {
        head=NULL;
        tail=NULL;
        first = 1;
        size--;
    }
    else if(head!=tail)// If there are more than one customers. we just move to the next customer.
    {
        head=head->next;
        size--;
    }

}

