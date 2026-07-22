#include <iostream>
using namespace std;

int second_largest_element(int arra[] , int Size)
{
    for(int i = 0 ; i < Size ; i++)
    {
        for(int j = 0  ; j < Size - i - 1 ; j++)
        {
            if(arra[j + 1] < arra[j])
            {
                int temp = arra[j];
                arra[j] = arra[j+1];
                arra[j+1] = temp;
            }
        }
    }

    for(int i = Size - 2 ;  i >= 0 ; i--)
    {
        if(arra[i] < arra[Size - 1])
        {
            return arra[i] ;
        }
    }

    return -1;
}

int main()
{
    int arra[] = {23 , 45 , 65, 15, 78, 34, 56, 70};
    int Size = sizeof(arra)/sizeof(int);

    int second = second_largest_element(arra, Size);

    cout << second;
}
