#include <iostream>
using namespace std;

int duplicate_remover(int arr[] , int size)
{
    int flag = 0 , top = 0 ;
    int arr2[size];

    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < top ; j++)
        {
            if(arr[i] == arr2[j])
            {
                flag = 1;
            }
        }

        if(flag == 0)
        {
            arr2[top] = arr[i];
            top++;
        }

        flag = 0;
    }


    for(int i = 0 ; i < top ; i++)
    {
        arr[i] = arr2[i];
    }

    return top;
}

int main()
{
    int arra[] = {1 , 2, 2, 2, 2, 4,5, 5, 7, 1, 3, 9, 0, 12, 12, 11};
    int size = sizeof(arra)/sizeof(int);

    int new_size = duplicate_remover(arra , size);

    for(int i = 0 ; i < new_size ; i++)
    {
        cout << arra[i] << " " ;
    }
}