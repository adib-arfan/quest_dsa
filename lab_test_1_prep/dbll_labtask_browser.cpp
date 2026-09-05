#include <iostream>
using namespace std;

class site
{
    public:

    string name;
    site *next , *prev;

    site(string n)
    {
       name = n;
       next = NULL;
       prev = NULL;
    }
};


class history
{
    public:

    site *head , *tail , *current;

    history()
    {
        head = NULL;
        tail = NULL;
    }

    void visit(string name)
    {
       site* new_site = new site(name);

       if(head == NULL)
       {
         current = head = tail = new_site;
         return;
       }

       new_site->prev = current;
       current->next = new_site;

       current = new_site;
       tail = new_site;

    }

    void back()
    {
        if(head == current)return;

        current = current->prev;
    }


    void forward()
    {
        if(current == tail)return;

        current = current->next;
    }


    void display()
    {
      site* temp = head;

      while (temp != NULL)
      {
        cout << temp->name <<"\n" ;
        temp = temp->next;
      }
      
    }
   
};

int main()
{
    string input , name;
    history h1;
    int flag = 0 ;


    while(1)
    {
        cin >> input;
          
       if(input == "VISIT")
       {
         cin >> name;
         h1.visit(name);
       }

       else if(input == "BACK")
       {
         h1.back();
       }

       else if(input == "FORWARD")
       {
        h1.forward();
       }

       else if(input == "EXIT")
       {
        break;
       }
       

    }


    h1.display();
    cout << h1.current->name <<"\n";
}