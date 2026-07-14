#include <iostream>
using namespace std;

typedef struct node Node;

struct node
{
   int data;
   Node* nxt; // arekta struct node ke point kore
};

Node* create_node(int item , Node* nxt) // notun created node take je pointer point kore seita return kore
{
    Node* new_node = new Node();

    new_node->data = item;
    new_node->nxt = nxt;

    return new_node;
}


Node* prepend(int item , Node* head)
{
    Node* new_node = create_node(item , head);
    return new_node;
}




int main()
{
    Node *n1 , *n2 , *head ;

    n1 = create_node(10, NULL); // aita akhn prothom node
    head = n1 ; // prothom node k point kore head

    head = prepend(20 , head); // new node ta head jake point kortesilo , take point korbe
                               // are new node ta k abr point korbe head

    n2 = head; // first node tar pointer , head o first node takei point kore

    cout << "The first data is " << n2->data << endl ;
    cout << "The second data is " << n1->data << endl;

}
