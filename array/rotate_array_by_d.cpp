//given an array of integers arr[] of size n , the task is to rotate the array elements to the left by d positions


// Input: arr[] = [1, 2, 3, 4, 5, 6], d = 2
// Output: [3, 4, 5, 6, 1, 2]
// Explanation: After first left rotation, arr[] becomes [2, 3, 4, 5, 6, 1] and after the second rotation, arr[] becomes [3, 4, 5, 6, 1, 2]

// Input: arr[] = [1, 2, 3], d = 4
// Output: [2, 3, 1]
// Explanation: The array is rotated as follows:

// After first left rotation, arr[] = [2, 3, 1]
// After second left rotation, arr[] = [3, 1, 2]
// After third left rotation, arr[] = [1, 2, 3]
// After fourth left rotation, arr[] = [2, 3, 1]


#include <iostream>
using namespace std;

void rotate_func(int arra[] , int Size , int rotate_by)
{

   

    while(rotate_by != 0)
    {
        int temp = arra[0];
        for(int i = 0 ; i < Size - 1 ; i++)
        {
            
            arra[i] = arra[i + 1];
           
        }

        arra[Size -1] = temp;  
        rotate_by--;
    }
}

int main()
{
    int size;
    int rotate_by;

     cout << "Size : " ; cin >> size;

     int *arra = new int[size];

     for(int i = 0 ; i < size ; i++)
     {
        cin >> arra[i] ;
     }

     cout << "rotate by : " ; cin >> rotate_by;

     rotate_func(arra , size , rotate_by);

     for(int i = 0 ; i < size ; i++)
     {
        cout << arra[i] << " ";
     }

}