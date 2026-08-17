#include <iostream>
using namespace std;

#define SIZE 100


class queue
{
    public:

    int q[SIZE];
    int front , rear ;

    queue()
    {
        front = -1 ;
        rear =  -1;
    }

    void enqueue(int num)
    {
        if(rear == SIZE - 1)
        {
            cout << "overflow" << endl ;
        }

        else if(rear == -1 && front == -1)
        {
            rear =  front = 0;
            q[rear] = num;
        }

        else
        {
            q[++rear] = num;
        }
    }


    int dequeue()
    {
        int val ;

        if(rear == -1)
        {
            cout << "underflow" << endl ;
            return -1;
        }

        else 
        {
           val = q[front++];

           if(front > rear)
           {
             front = rear = -1 ;
           }
        }
      return val ;
    }
};

// Queue is used for :
// CPU & Disk scheduling
// when data is transferred asynchronously between two processes,
// the queue is used there for synchronization
// Handling interrupts in real time systems 
// call center phone systems use queues to hold people calling them in order 


int main()
{
    queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(7);

    q.dequeue();

    for(int i = 0 ; i < 4 ; i++)
    {
        cout << q.dequeue() << endl ;
    }

}