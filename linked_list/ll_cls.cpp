#include <iostream>
using namespace std;

class Node
{
public:

    int data;
    Node* next;

    Node()
    {
        data = 0 ;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class linked_list
{
    Node* head;

 public:
    
     linked_list()
     {
        head = NULL;
     }

     void insert_front(int val)
     {
        Node* new_node = new Node(val);
        new_node->next = head ;
        head = new_node;
     }


     void insert_after(int key , int value)
     {
        Node* temp =  head ;

        while(temp != NULL && temp->data != key)
        {
            temp = temp->next ;
        }

        if(temp == NULL)
        {
            cout << "value not found " << endl ;
        }

        Node* new_node = new Node(value);
        new_node ->next = temp->next;
        temp->next = new_node;
     }


     void insert_last(int value)
     {
        Node* new_node = new Node(value);

        if(head == NULL)
        {
            head = new_node;
            return;
        }

        Node* temp = head ;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new_node;
     }


   void delete_first()
   {
       if(head == NULL)
       {
        return ;
       }

       Node* temp = head;

       head = head->next;
       delete temp;
   }


   void delete_last()
   {
    
       if(head == NULL)
       {
        return ;
       }

       
       if(head->next == NULL)
       {
        delete head;
        head == NULL ;
        return ;
       }

       
       Node* temp = head;

       while(temp->next->next != NULL)
       {
           temp = temp->next;
       }

       delete temp->next;
       temp->next = NULL ;
   }


    //function to delete the 
    //node at a given position 

    void delete_node(int offset)
    {
        Node *temp1 = head , *temp2 = NULL;
        int list_length = 0;

        if(head == NULL)
        {
            cout << "list empty" << endl ;
            return;
        }

        while(temp1 != NULL)
        {
            temp1 = temp1->next;
            list_length++;
        }

        temp1 = head;

        if(offset == 1)
        {
            head = head->next;
            delete head;
            return;
        }

        while(offset-- > 1)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }

        temp2->next = temp1->next;
        delete temp1;
    }


};