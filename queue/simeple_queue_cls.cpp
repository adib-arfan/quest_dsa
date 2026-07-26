#include <iostream>
using namespace std;

#define MAX 10


struct quueue
{
   int queueue[MAX];
   int front = -1 , rear = -1 ;
};

void enquueue(int num , struct quueue * que)
{
    if(que->rear == MAX - 1)
    {
        cout << "overflow" << endl ;
    }

    else if (que->rear == -1 && que->front == -1)
    {
        que->front = que->rear = 0;
        que->queueue[que->rear] =  num ;
    }
    else
    {
        que->rear++ ;
        que->queueue[que->rear] =  num ;
    }

    
}


int dequueue(struct quueue *que)
{
    int val;
    
    if(que->front == -1 || que->front > que->rear)
    {
        cout << "underflow" << endl ;
        return -1;
    }

    else
    {
        val = que->queueue[que->front++] ;

        if(que->front > que->rear)
        {
            que->front = -1;
            que->rear = -1;
        }

        return val;
    }
}

int main()
{
   struct quueue *que;

   que =  new quueue();

   enquueue(7 , que);
   enquueue(8 , que);
   enquueue(9 , que);
   enquueue(10 , que);
   enquueue(11 , que);

   for(int i = 0 ; i < 5 ; i++)
   {
    cout << dequueue(que) << " ";
   }


}