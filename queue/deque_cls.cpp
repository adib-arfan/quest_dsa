#include <iostream>
using namespace std;

#define SIZE 10

struct cdeque
{
   int deque[SIZE];
   int left = -1 , right = -1;
};

void insert_right(cdeque *dq , int val)
{
    if(dq->left == -1 && dq->right == -1)
    {
        dq->left = dq->right = 0;
        dq->deque[dq->right] = val;
    }

    else if(dq->left == (dq->right + 1) % SIZE)
    {
        cout << "overflow" << endl ;
    }

    else
    {
        dq->right = (dq->right + 1) % SIZE ;
        dq->deque[dq->right] = val ;
    }
}


void insert_left(cdeque *dq , int val)
{
     if(dq->left == -1 && dq->right == -1)
     {
        dq->left = dq->right = 0;
        dq->deque[dq->left] = val;
     }

     else if(dq->left == (dq->right + 1) % SIZE)
     {
        cout << "overflow" << endl ;
     }

     else
     {
        dq->left =( dq->left - 1 + SIZE ) % SIZE ;
        dq->deque[dq->left] = val;
     }
} 


int delete_left(cdeque *dq)
{
    if(dq->left == -1 && dq->right == -1)
    {
        cout << "underflow" << endl ;
        return -1;
    }

    int val = dq->deque[dq->left];

    if(dq->left == dq->right)
    {
        dq->left = dq->right = -1 ;
    }

    else
    {
        dq->left = (dq->left + 1) % SIZE;
    } 
  return val;
}


int delete_right(cdeque *dq)
{
    if(dq->left == -1 && dq->right == -1)
    {
        cout << "underflow" << endl ;
        return -1;
    }

    int val = dq->deque[dq->right];

    if(dq->left == dq->right)
    {
        dq->left = dq->right = -1 ;
    }

    else
    {
        dq->right = (dq->right - 1 + SIZE) % SIZE;
    }
}

