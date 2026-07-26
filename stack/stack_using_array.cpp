//from geeksforgeeks

#include<iostream>
using namespace std;

typedef struct 
{
    int *arr;
    int capacity;
    int top;
}Stack;

Stack *create_stack(int capacity)
{
    Stack *stck = new Stack();
    stck->capacity = capacity;
    stck->arr = new int[capacity];
    stck->top = -1;

    return stck;
}


void push(Stack *stck , int x)
{
    if(stck->top == stck->capacity - 1)
    {
        cout << "Stack overflow" << endl ;
        return;
    }

    stck->arr[++stck->top] = x;
}

int pop(Stack* stck , int x)
{
    if(stck->top == -1)
    {
        cout << "Stack underflow" << endl ;
        return -1;
    }

    return stck->arr[stck->top--];
}

int peep(Stack* stck)
{
    if(stck->top == -1)
    {
        return -1;
    }

    return stck->arr[stck->top];
}


bool is_empty(Stack* stck)
{
    return stck->top == -1 ;
}

bool is_full(Stack* stck)
{
    return stck->top = stck->capacity - 1;
}


void free_stack(Stack * stck)
{
    delete stck->arr;
    delete stck;
}

int main()
{
    
}