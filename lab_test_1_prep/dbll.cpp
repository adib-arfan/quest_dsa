#include <iostream>
using namespace std;

class Node
{
    public:
    
    int value;
    Node *next , *prev;

    Node(int val)
    {
       value = val;
       next = NULL;
       prev = NULL;
    }
};


class dll
{
    Node* head;
    Node* tail;

    public:

       dll()
       {
        head = NULL ;
        tail = NULL ;
       }


       
       void insert_back(int val)
       {
          Node *new_node = new Node(val);

          if(head == NULL)
          {
            head = new_node;
            tail = new_node;
            return;
          }


          new_node->prev = tail;
          tail->next = new_node;
          tail = new_node;
       
       }


       void insert_front(int val)
       {
        Node* new_node = new Node(val);
        
        if(head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;

       }



       void insert_b4_elmnt(int key , int val)
       {
          Node* curr = head ;

          Node* new_node = new Node(val);

          while(curr->value != key && curr != NULL)
          {
            curr = curr->next;
          }

          if(curr == NULL)
          {
            return;
          }

          if(curr == head)
          {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
            return;
          }

          new_node->prev = curr->prev;
          new_node->next = curr;
          curr->prev->next = new_node;
          curr->prev = new_node;


       }


       void insert_after_given_element(int key , int val)
       {
           Node* nee_node = new Node(val);
           Node* curr = tail;


           while(curr->value != key && curr != NULL)
           {
             curr = curr->prev;
           }

           if(curr == NULL)
           {
              return;
           }

           if(curr == tail)
           {
             nee_node->prev = tail ;
             tail->next = nee_node;
             tail = nee_node;
             return;
           }

           nee_node->next = curr->next;
           nee_node->prev = curr;
           curr->next->prev = nee_node;
           curr->next = nee_node;

       }


       void delete_front()
       {
          Node* temp = head;
     
          if(head == NULL) return;

          if(head == tail)
          {
            head = tail = NULL ;
            return;
          }

         head = head->next;
         head->prev = NULL ;

          delete temp;
          
       }

       void delete_back()
       {
        Node* temp = tail ;

        if(tail == NULL)return;

        if(head == tail)
        {
            head = tail = NULL;
            return;
        }


        tail = tail->prev;
        tail->next = NULL;
      
    
    }


    void delete_element(int key)
    {
        Node *curr = head;

        while(curr != NULL && curr->value != key)
        {
            curr = curr->next;
        }

        if(curr == NULL)
        {
            return;
        }

        if(curr == head)
        {
            delete_front();
            return;
        }

        if(curr == tail)
        {
            delete_back();
            return;
        }

        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;

        delete curr;
    }

    void delete_after_given_element(int key)
    {
        if(head == NULL)return;

        Node *temp , *curr;

        curr = head;

        while(curr != NULL && curr->value != key)
        {
            curr = curr->next;
        }

        if(curr == NULL)return;

        if(curr == tail)return;


        temp = curr->next;


        
        curr->next->next->prev = curr;
        curr->next = curr->next->next;
       
        delete temp;



    }


    void delete_before_element(int key)
    {
        if(tail == NULL)return;

        Node *temp , *curr;

        curr = tail;

        while(curr != NULL && curr->value != key)
        {
            curr = curr->prev;
        }

        
        if(curr == NULL)return;

        if(curr == head)return;


        temp = curr->prev;

        curr->prev->prev->next = curr;
        curr->prev = curr->prev->prev;

        delete temp;
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
    dll l1;

    l1.insert_front(12);
    l1.insert_front(11);
    l1.insert_front(10);
    l1.insert_back(13);
    l1.insert_after_given_element(12,122);
    l1.insert_b4_elmnt(12,121);
    l1.insert_back(14);
    l1.insert_back(15);
    l1.delete_before_element(15);
    l1.delete_element(122);
    

    l1.display();
}