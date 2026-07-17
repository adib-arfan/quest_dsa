#include<iostream>
using namespace std;

typedef struct node Node;

struct node
{
   int data;
   Node* next;
};

Node* create_node(int data , Node* next)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = next;

    return new_node;
}


Node* prepend(int data , Node* head)
{
    Node* new_node = create_node(data , head);
    return new_node;
}

Node* append(int data , Node* head)
{
    Node* new_node = create_node(data , NULL);
     
    if(head == NULL)
    {
        return new_node;
    }

    Node* current_node = head ;

    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }

    current_node->next = new_node;
    
    return head;
}

void print_linked_list(Node* head)
{
    Node* current_node = head;

    while(current_node != NULL)
    {
        cout << current_node->data << endl ;
        current_node = current_node->next ;
    }

    cout <<"\n\n" ;
}


int count(Node* head)
{
    int count = 0;

    Node* current_node = head ;

    while(current_node != NULL)
    {
        count++ ;
        current_node = current_node->next;
    }

    return count;
}


Node* search(Node *head , int item)
{
    Node* current_node  = head ;

    while(current_node != NULL)
    {
        if(current_node->data == item)
        {
            return current_node ;
        }

        current_node = current_node->next ;
    }

    return NULL ;
}



Node* remove_node(Node* head , Node* node)
{
    if(head == node)
    {
        head = node->next;
        delete node;
        return head;
    }

    Node* current_node = head;

    while(current_node != NULL)
    {
        if(current_node->next == node)
        {
            break;
        }
      current_node = current_node->next;
    }

    if(current_node == NULL)
    {
        return head;
    }

    current_node->next = node->next ;
    delete node;
    return head;
}


void insert_node(int item , Node* node)
{
    Node* new_node = create_node(item , node->next);

    node->next = new_node;
}



// int main()
// {
//     Node *n1 , *head;

//     n1 = create_node(10, NULL);

//     head = n1 ;

//    // print_linked_list(head);

//     head = prepend(20 , head);
//    // print_linked_list(head);

//     head = append(30 , head);
//    // print_linked_list(head);



//     // int n = count(head);

//     // cout << n;


//     head = append(50 , head);
//     head = append(60 , head);
//     head = append(89 , head);

//     head = prepend(45 , head);

//     //print_linked_list(head) ;

//     Node* n = search(head , 60);

//     cout << n->data << endl;
//     cout << n->next->data << endl ;

// }

// int main()
// {
//     Node *n1 , *head , *n2 ;
    
//     n1 = create_node(10, NULL);

//     head = n1 ;
    
//     print_linked_list(head);

//     head = prepend(20 , head);
//     print_linked_list(head);

//     head = append(30 , head);
//     print_linked_list(head);

//     head = remove_node(head , n1);
//     print_linked_list(head);

//     n2 = head;
//     head = remove_node(head , n2);
//     print_linked_list(head);


// }

int main()
{
    Node *n1 , *head , *n2 ;

    n1 = create_node(11, NULL);
    head = n1;
    
    head = append(23 , head);
    head = prepend(41 , head);
    head = append(67 , head);
    head = prepend(50 , head);

    print_linked_list(head);

    n2 = search(head , 41);

    insert_node(999999, n2);

    print_linked_list(head);
}