#include <iostream>
using namespace std;


void bubbles_sort(int arra[] , int size)
{
    bool swapped = true ;

    for(int i = size - 1 ; i > 0  && swapped ; i--)
    {
        swapped = false;

        for(int j = 0 ; j < i ; j++)
        {
            if(arra[j] > arra[j + 1])
            {
                int temp = arra[j + 1];
                arra[j + 1] = arra[j];
                arra[j] = temp;
                swapped = true ; 
            }
        }
    }
}


//bairer loop ta ami size - 1 theke 1 porjonto ghurabo 
//ar inner loop e bairer iterator shoman comparison thakbe 

//this algorithm is offline because it needs the whole input before it starts producing the correct final result 
//it is stable because the relative order of equal elements are never changed as equal elements are never swapped 



int main()
{
    int arra[] = {5 , 1, 4, 2, 3};
    int size =  sizeof(arra)/sizeof(int);

    bubbles_sort(arra , size);

    for(int i = 0 ; i < size ; i++)
    {
        cout << arra[i] << " " ; 
    }

}