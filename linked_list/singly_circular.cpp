#include <iostream>
using namespace std;


class Node
{
    public:

    int value;
    Node* next;

    Node(int val)
    {
        value = val;
        next = nullptr;
    }
};

class circ_list
{
    Node* head;
    Node* tail;

    public:

    circ_list()
    {
        head = nullptr;
        tail = nullptr;      
    }

    void append(int val)
    {
        Node* newnode = new Node(val);
        
        if(head == nullptr)
        {
            head = newnode;
            tail = newnode;
            newnode->next = head ;
            return;
        }

        newnode->next = 

    }



};
