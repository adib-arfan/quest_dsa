#include <iostream>
using namespace std;

template<typename T , int size>
class my_circular_queue
{
   int head , tail ;
   T* quue ;

   public:

   my_circular_queue(): head(0) , tail(0)
   {
    quue = new T[size + 1];
   }

   ~my_circular_queue()
   {
    delete[] quue;
   }


   void enquuue(T val)
   {
    if((tail + 1) % (size + 1) == head)
    {
        throw overflow_error("The queue is full !");
    }
    else
    {
        quue[tail] = val ;
        
        tail = (tail + 1) % (size + 1) ;
    }
   }


   T dequuue()
   {
     T val ;
     if(tail == head)
     {
        throw underflow_error("The queue is empty :(" );
     }
     else
     {
         val = quue[head];
         head = (head + 1) % (size + 1); 
     }

     return val ;

   }

};

int main()
{
    my_circular_queue<int , 5> my_q;

    my_q.enquuue(1);
    my_q.enquuue(2);
    my_q.enquuue(3);
    my_q.enquuue(4);
    my_q.enquuue(5);
    my_q.enquuue(6);


    for(int i = 0 ; i < 5 ; i++)
    {
        cout << my_q.dequuue() << endl ;
    }
}