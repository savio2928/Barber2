
using namespace std;
#include "Random.h"
#include "Customer.h"


//Here we have set values to the variables and called a Randomvalue function that takes in the maximum range, and gives us an output from the 1 to the maximum range

Customer::Customer(int n):id(n), next(NULL)
{
    hairCutTime= RandomValue(5);
}

