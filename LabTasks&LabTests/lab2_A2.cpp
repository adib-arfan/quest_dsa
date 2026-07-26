#include <iostream>
using namespace std;

int head = -1 , rear = -1;

void enque(int arra[] , int n)
{
   if(head == -1 && rear == -1)
   {
    head = rear = 0;
    arra[rear] = n ; 
   }

   else
   {
    arra[++rear] = n ;
   }
}

int deque(int arra[])
{ 
   int val = arra[head++];
   return val;
}

int special_shuffle(int arra[]  , int size)
{
    int n ,m , i = 0, o;

    for(int k = 0 ; k < size ; k++)
    {
        cin >> n;
        enque(arra, n);
    }

    while(head !=  rear)
    {
        if(i%2 == 0)
        {
            m = deque(arra);
            i++;
        }
        else
        {
           o = deque(arra);
           enque(arra , o);
           i++;
        }
    }

    int val = arra[head];
    return val;
}

int main()
{
    int arra[500];
    int size ;
    cin >> size ;

    int val = special_shuffle(arra , size);

    cout << val << endl ;
}