#include <iostream>
using namespace std;

void reverse_array(int arra[] , int Size)
{
    
    int left = 0 , right = Size - 1;

    while(left < right)
    {
        int temp = arra[right];
        arra[right] = arra[left];
        arra[left] = temp;

        left++;
        right--;
    }

}

int main()
{
    int arra[] = {12 , 34, 25, 67 , 68, 98, 100 , 45};
    int Size = sizeof(arra)/sizeof(int);

    reverse_array(arra, Size);

    for(int i = 0 ; i < Size ; i++)
    {
        cout << arra[i] << " " ;
    }
}