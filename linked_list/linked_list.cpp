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



Node* append(int item , Node* head)
{
    Node* new_node = create_node(item , NULL); // jehetu sesh er node tai kauke point kore na 

    if(head == NULL) // tar mane new node tai first node ar aitai return kore dibe 
    {
        return new_node;
    }

    //ar naile loop chalai shesh node ta ber korte hobe

    Node* current_node = head ; // prothome head jake point kore ase take diye start korbe

    //sesh node ta kauke nirdesh korbe na , er next hobe NULL

    while(current_node->nxt != NULL)
    {
        current_node = current_node->nxt;
    }

    //current node ta sesh node, tai er porer node ta hobe amdr new node

    current_node->nxt = new_node;

    return head;
}


void print_linked_list(Node* head)
{
    Node* current_node = head;

    while(current_node != NULL)
    {
        cout << current_node->data << endl;
        current_node = current_node->nxt;
    }

    cout << "\n\n\n" ;
}





Node* remove_node(Node* head , Node* node) // head ar jei node ta dlt korbo sei node tar pointer , head ptr ta return korbe 
{
    if(node == head)
    {
        head = node->nxt ;

        delete node;

        return head;
    }

    //code aikhane ashche mane node ll er first node na 
    //node er ager node ta khuje ber korte hobe 
    //sei node ta current_node hoile node hobe current_node->nxt

    Node* current_node = head;

    while(current_node != NULL)
    {
        if(current_node->nxt == node)
        {
            break;
        }

        current_node = current_node->nxt ; // aita diye just traverse kortesi arki , oijonno to update kora lagbe current_node take
    }

    if(current_node == NULL)// mane oi node ta nai arki list e
    {
        return head ;
    }

    //jehetu node muche felte chaitesi tai current_node->nxt akhn node er porer node take point korbe

    current_node->nxt = node->nxt ;

    delete node;

    return head;
}




void insert_node(Node *node , int item) // *node hocche jar pore amra notun node ta insert korbo
{
    Node* new_node = create_node(item , node->nxt);

    node->nxt = new_node;
}






int main()
{
    // Node *n1 , *n2 , *head ;

    // n1 = create_node(10, NULL); // aita akhn prothom node
    // head = n1 ; // prothom node k point kore head

    // head = prepend(20 , head); // new node ta head jake point kortesilo , take point korbe
    //                            // are new node ta k abr point korbe head

    // n2 = head; // first node tar pointer , head o first node takei point kore

    // cout << "The first data is " << n2->data << endl ;
    // cout << "The second data is " << n1->data << endl;



    Node *n1 , *head;

    n1 = create_node(10 , NULL);
    head = n1 ;

    print_linked_list(head);

    head = append(20 , head);
    print_linked_list(head);

    head = append(30 , head);
    print_linked_list(head);


}
