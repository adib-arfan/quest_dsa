#include <iostream>
using namespace std;

#define MAX 5

class doubleEndedQueue
{

    int left , right;
    int dq[MAX];

public:

    doubleEndedQueue()
    {
        left = right = -1;
    }

    
    void insert_right(int val)
    {
        if(right == -1 && left == -1)
        {
            right = left = 0 ;
            dq[right] = val;
        }

        else if(left == (right + 1) % MAX)
        {
            cout << "Overflow" << endl ;
        }

        else
        {
            right = (right + 1) % MAX;
            dq[right] = val;
        }
    }


    void insert_left(int val)
    {
        if(right == -1 && left == -1)
        {
            right = left = 0;
            dq[left] = val;
        }

        else if(left == (right + 1) % MAX)
        {
            cout << "Overflow" << endl ;
        }

        else
        {
            left = (left - 1 + MAX) % MAX ;
            dq[left] = val;
        }
    }


    int delete_left()
    {
        if(right == -1 && left == -1)
        {
            cout << "Underflow" << endl ;
            return -1;
        }

        int val = dq[left];

        if(right == left)
        {
            right = left = -1 ;
        }
        else
        {
            left = (left + 1) % MAX;
        }

        return val;
    }


    int delete_right()
    {
        if(right == -1 && left == -1)
        {
            cout << "Underflow" << endl ;
            return -1;
        }

        int val = dq[right];

        if(right == left)
        {
            right = left = -1 ;
        }

        else
        {
            right = (right - 1 + MAX) % MAX;
        }

        return val;
    }
};


int main()
{
   doubleEndedQueue dq;

   dq.insert_right(1);
   dq.insert_right(2);
   dq.insert_right(3);
   dq.insert_right(4);
   dq.insert_right(5);

   int m = dq.delete_left();

   dq.insert_left(6);
   dq.insert_left(7);

   for(int i = 0 ; i < MAX ; i++)
   {
    cout << dq.delete_right() << endl ;
   }

}