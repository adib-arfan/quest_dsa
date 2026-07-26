#include <iostream>
using namespace std;


#define SIZE 10 

struct circ_queue
{
    int cir_q[SIZE]; 
    int front = -1;
    int rear = -1;
};

void enquueue(circ_queue *cque , int val)
{
    if(cque->front == -1 && cque->rear == -1)
    {
        cque->front = cque->rear = 0;
        cque->cir_q[cque->rear] = val;
    }
    
    else if(cque->front == (cque->rear + 1) % SIZE)
    {
        cout << "overflow" << endl ;
    }

    else 
    {
        cque->rear = (cque->rear + 1) % SIZE;
        cque->cir_q[cque->rear] = val;
    }
}

int dequueue(circ_queue *cque)
{
    int val ;
    
    if(cque->front == -1 && cque->rear == -1)
    {
        cout << "underflow" << endl ;
        return -1;
    }

    val = cque->cir_q[cque->front];

    if(cque->front == cque->rear)
    {
        cque->front = cque->rear = -1;
    }

    else
    {
        cque->front = (cque->front + 1) % SIZE ;
    }

  return val;

}

int main()
{
   circ_queue *cque;

   cque = new circ_queue();

   enquueue(cque , 10);
   enquueue(cque , 20);
   enquueue(cque , 30);
   enquueue(cque , 40);
   enquueue(cque , 50);
   enquueue(cque , 60);
   enquueue(cque , 70);
   enquueue(cque , 80);
   enquueue(cque , 90);
   enquueue(cque , 100);
   enquueue(cque , 110);
   enquueue(cque , 120);

   for(int i = 0 ; i < SIZE / 2; i++)
   {
    cout << dequueue(cque) << " ";
   }

   cout << endl ;

   enquueue(cque , 110);
   enquueue(cque , 120);
   enquueue(cque , 130);
   enquueue(cque , 140);
   enquueue(cque , 150);

   
   for(int i = 0 ; i < SIZE ; i++)
   {
    cout << dequueue(cque) << " ";
   } 
}