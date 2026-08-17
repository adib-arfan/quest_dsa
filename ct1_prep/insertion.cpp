#include <iostream>
using namespace std;


void insertion_sort(int arra[] , int size)
{
    for(int i = 1 ; i < size ; i++)
    {
        int val = arra[i];
        int j = i ;

        while(j != 0 && arra[j-1] > val)
        {
            arra[j] = arra[j - 1];
            j--;
        }

        arra[j] = val;
    }
}

// an algorithm is online if it can process input elements one at a time 
// and still maintain a valid sorted result at every step 
    

//for each new element insertion sort shifts it leftwards
//past everything strinctly greater than it 
//and stops the moment it hits an element that is less than
//or equal to it 

//so when a new element is equal to something already placed ,
//it never jumps ahead of it 
//so the relative position is maintained and hence 
//insertion sort is stable 

int main()
{
    int arra[] = {5 , 1, 4, 2, 3};
    int size =  sizeof(arra)/sizeof(int);

    insertion_sort(arra , size);

    for(int i = 0 ; i < size ; i++)
    {
        cout << arra[i] << " " ; 
    }

}