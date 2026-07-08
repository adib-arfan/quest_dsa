#include <iostream>
using namespace std;

template <typename T>
class my_stack
{
    int top , capacity;
    T* stck;

    void resize()
    {
        capacity *= 2 ;

        T* new_stck = new T[capacity];

        for(int i = 0 ; i < top ; i++)
        {
            new_stck[i] = stck[i] ;
        }

        delete[] stck;

        stck = new_stck;
    }

    public:

    my_stack()
    {
        top = 0; 
        capacity = 2 ;
        stck = new T[capacity] ;
    }

    ~my_stack()
    {
        delete[] stck;
    }

    void push_stack(T val)
    {
        if(top == capacity)
        {
            resize();
        }
      
        stck[top] = val ;
        top++ ; 
    }

    T pop_stack()
    {
        if(top == 0)
        {
            throw underflow_error("The stack is empty!");
        }
        else
        {
            top--;
            return stck[top];
        }
    }

    int get_top()
    {
        return top;
    }
};

// int main()
// {
//     my_stack<string> strara;

//     strara.push_stack("hello");
//     strara.push_stack("hi");
//     strara.push_stack("bye");
//     strara.push_stack("bye");


//     int n = strara.get_top();

//     for(int i = 0 ; i < n ; i++)
//     {
//         cout << strara.pop_stack() << endl ;
//     }
// }