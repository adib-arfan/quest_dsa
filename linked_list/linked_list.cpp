#include<iostream>
using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *next;
};


Node* create_node(int data, Node* nxt)
{
    Node* new_node = new Node();

    new_node->data  = data;
    new_node->next = nxt;

    return new_node;
}

Node* prepend(int item , Node* head)
{
    Node* new_node = create_node(item , head); // jei node ta ami pabo , seita notun data shoho notun akta node
                                               // jeita point kore thakbe head age jake point kortesilo take

    return new_node;
}

int main()
{
    Node* n1 , *n2 , *head , *n3;

    n1 = create_node(10 , NULL);
    head = n1 ;

    head = prepend(20 , head); // notun akta node toiri hobe , head age jake point kortesilo , aitar *next take point korbe
                        // ar notun node take point korbe hocche head  

    n2 = head ;

    cout << "The first data " << n2->data << endl ;

    n3 = n2->next;

    cout << "The second data " << n3->data << endl ;
}