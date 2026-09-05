#include <iostream>
using namespace std;

#define SIZE 5

class dq
{
    public:

    int right , left;
    int dek[SIZE];

    dq()
    {
        right = left = -1;
    }

    void insertRight(int val)
    {
        if(left ==  -1 && right == -1 )
        {
          left = right = 0 ;
            dek[right] = val;
              
        }
        else if(left == (right + 1) % SIZE)
        {
            cout << "overflow" << endl ;
        }
        else
        {
            right = (right + 1) % SIZE ;
            dek[right] = val;
        }
    }


    void insertLeft(int val)
    {
       if(left == right == -1)
        {
            left = right = 0 ;
            dek[left] = val;
        }
        else if(left == (right + 1) % SIZE)
        {
            cout << "overflow" << endl ;
        }
        else
        {
            left = (left - 1 + SIZE) % SIZE ;
            dek[left] = val;
        }
    }

    int deleteRight()
    {
        if(right == -1 && left == -1)
        {
            cout << "underflow"  << endl ;
            return -1;
        }

        if(left == right)
        {
            left = right = -1 ;
        }

        int value = dek[right];
        right = (right - 1 + SIZE) % SIZE;
        return value;
    }

    int deleteLeft()
    {
        if(right == -1 && left == -1)
        {
            cout << "underflow"  << endl ;
            return -1;
        }

        if(left == right)
        {
            left = right = -1 ;
        }

        int value = dek[left];
        left = (left + 1) % SIZE;
        return value;
    }
};

int main()
{
    
}