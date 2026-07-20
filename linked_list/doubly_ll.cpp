#include <iostream>
using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node* next;
    Node* prev;
};

Node* create_node(int data , Node *next , Node *prev)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = next;
    new_node->prev = prev;

    return new_node;
}


Node* prepend(int data , Node *head)
{
    Node *new_node = create_node(data , head , NULL);
    new_node->next->prev = new_node;

    return new_node; // return ta korte hobe head e , jate head ai notun node take point kore thake 
}




Node* append(int data ,  Node *head)
{
    Node *new_node =  create_node(data , NULL , NULL);

    if(head == NULL)
    {
        return new_node;

/*
    head ----->        -------> NULL
                 NODE1 
    NULL <-----     

*/
    }

    Node *current_node = head ;

    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }

    
    current_node->next = new_node;
    new_node->prev = current_node;

    return head;
}