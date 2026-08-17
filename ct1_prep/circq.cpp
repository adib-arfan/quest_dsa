#include <iostream>
using namespace std;

#define MAX 5

class circular_queue
{
  public:  
  
  int front , rear ;
  int cirq[MAX];

  circular_queue()
  {
    front = rear = -1;
  }

  
  void enqueue(int val)
  {
    if(front == -1  && rear == -1)
    {
        front = rear = 0;
        cirq[rear] = val;
    }

    else if(front == (rear + 1) % MAX)
    {
        cout << "overflow!" << endl;
    }

    else
    {
        rear = (rear + 1) % MAX ;
        cirq[rear] = val;
    }
  }


  int dequeue()
  {
    if(front == -1 && rear == -1)
    {
        cout << "underflow!" << endl;
        return -1;
    }

    int val = cirq[front];

    if(front == rear)
    {
        rear = front = -1;
    }

    else
    {
        front = (front + 1) % MAX;
    }

    return val;
  }

};

int main()
{
    circular_queue cq;

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);
    cq.enqueue(6);


    for(int i = 0 ; i < MAX + 1; i++)
    {
        cout << cq.dequeue() << endl ;
    }



}