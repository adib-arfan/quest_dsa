#include <iostream>
using namespace std;

class song
{
    public:

    string name;
    song *next ,*prev;

    song(string n)
    {
        name = n;
        next = nullptr;
        prev = nullptr;
    }
};

class playlist
{
    public:

    song *head , *tail ;

    
    song *current;

    playlist()
    {
        head = tail = nullptr;
    }

    void add_back(string name)
    {
       song *new_song = new song(name);
       
       if(head == nullptr)
       {
        head = tail = new_song;
        return;
       }

       new_song->prev = tail;
       tail->next = new_song;
       tail = new_song;
    }

    void next_song()
    {
        if(current == tail)return;

        current = current->next;
    }

    void prev_song()
    {
        if(current == head)return;

        current = current->prev;
    }

    //original delete function written by me 
    //   void delete_()
    // {
    //    if(current == tail)
    //    {
    //     song *temp =current;

    //     tail = tail->prev;
    //     tail->next = nullptr;
    //     current = tail;
    //     delete temp;
    //     return;
    //    }

    //  song* temp  = current;
    //  song* temp1 = current->next;

    //  current->prev->next = current->next;
    //  current->next->prev = current->prev;
    //  delete temp;
    //  current = temp1;
    // }

    //got help from claude 
    void delete_()
    {
        if(current == nullptr) return;
 
        song *temp = current;
 
        // Case 1: only one song in the list
        if(current == head && current == tail)
        {
            head = tail = current = nullptr;
        }
        // Case 2: deleting the head (but not the only song)
        else if(current == head)
        {
            head = head->next;
            head->prev = nullptr;
            current = head;
        }
        // Case 3: deleting the tail (but not the only song)
        else if(current == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
            current = tail;
        }
        // Case 4: deleting a middle node
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            current = current->next;
        }
 
        delete temp;
    }
 
    void display()
    {
        song* curr = head;
 
        while(curr != nullptr)
        {
            cout << curr->name << endl;
            curr = curr->next;
        }
    }


    
};


int main()
{
    string names[4];
    playlist p1;
    string option;

    for(int i = 0 ; i < 4 ; i++)
    {
        cin >> names[i];
    }

    for(int i = 0 ; i < 4 ; i++)
    {
        p1.add_back(names[i]);
    }

    p1.current = p1.head;

    while (1)
    {
        cin >> option;

        if(option == "NEXT")
        {
            p1.next_song();
        }
        else if(option == "DELETE")
        {
            p1.delete_();
        }
        else if(option == "PREV")
        {
            p1.prev_song();
        }
        else if(option == "EXIT")
        {
            break;
        }
    }

    p1.display();

    cout << "Current track : " << p1.current->name << endl ; 
    
}

