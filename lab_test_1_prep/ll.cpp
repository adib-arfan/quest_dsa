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
        next = NULL;
    }
};

class li_list
{
    Node* head;

    public:

    li_list()
    {
        head = NULL ;
    }
    
    void append(int val)
    {
        Node* new_node = new Node(val);

        if(head == NULL)
        {
            head = new_node;
            return;
        }
        else
        {
            Node* current_node = head ;
           
            while (current_node->next != NULL)
            {
                current_node = current_node->next;
            }

            current_node->next = new_node;
            
        }
    }


    void prepend(int val)
    {
         Node* new_node = new Node(val);

        if(head == NULL)
        {
            head = new_node;
            return;
        }

        else
        {
            new_node->next = head;
            head = new_node;
        }
    }


    void insert_after_value(int key , int val)
    {
        Node* new_node = new Node(val);

        Node* current =  head;

        while(current->value != key)
        {
            current = current->next;
        }
  
        new_node->next = current->next;
        current->next = new_node;
    }


    void delete_from_begining()
    {
         Node* temp = head;

         head = head->next;

         delete(temp);

    }

    void delete_from_end()
    {
        Node* temp = head ;

        if(head == NULL)
        {
            return;
        }

        if (head->next == NULL) 
        {
           delete head;
           head = NULL;
           return;
        }

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        Node* temp2 = temp->next;

        temp->next =  NULL;
        delete temp2;
    }



    void delete_with_val(int key)
    {
      
        if(head == NULL)
        {
            return;
        }

        if (head->value == key)
        {
           Node *toDelete = head;
           head = head->next;
           delete toDelete;
           return;
        }

        Node *temp1 = head , *temp2  = head;

        
        while(temp1->value != key)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }

        temp2->next = temp1->next;
        delete temp1;
    }


    void delete_after_val(int key)
    {
         if(head == NULL)
        {
            return;
        }

        if (head->value == key)
        {
           Node *toDelete = head;
           head = head->next;
           delete toDelete;
           return;
        }

        Node *temp1 = head , *temp2  = head;

        
        while(temp1->value != key)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }

         temp2 = temp1;
         temp1 = temp1->next;

        
         temp2->next = temp1->next;
         delete temp1;
       
    }

    void display()
    {
        Node* temp = head;

        while(temp != NULL)
        {
            cout << temp->value << endl ;
            temp = temp->next;
        }
    }




};


int main()
{
    li_list l1;
    l1.prepend(23);
    l1.append(14);
    l1.prepend(56);
    l1.insert_after_value(23 , 232);
    l1.append(143);
    l1.prepend(24);
    l1.insert_after_value(56 , 57);

    l1.delete_after_val(23);



    // l1.delete_from_begining();
    // l1.delete_from_end();
    //l1.delete_with_val(23);

    l1.display();

}