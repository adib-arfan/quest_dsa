#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Human
{
     public:
    int ID ;
    string name;
    string blood;
    string address;

   
    Human(int i , string n , string b , string c): ID(i) , name(n) , blood(b) , address(c) {}
   
};


class human_graph
{
    vector<Human> nodes;
    vector<vector<int>> adjlist;
    vector<vector<int>> adjmtx;
    bool is_directed;


    public:

    human_graph(bool directed = false): is_directed(directed){}

    
    
    
    int add_node(string name , string blood , string city)
    {
        int id = nodes.size();

        Human new_person(id , name , blood , city);
        nodes.push_back(new_person);

        vector<int> new_empty_list;
        adjlist.push_back(new_empty_list);

        for(int i = 0 ; i < adjmtx.size() ; ++i)
        {
            adjmtx[i].push_back(0);
        }

        int total_nodes = nodes.size();

        vector<int> new_row(total_nodes , 0);
        adjmtx.push_back(new_row);

        return id;
    }

   

   
    void add_edge(int u , int v)
    {
       adjlist[u].push_back(v);
       adjmtx[u][v] = 1;

       if(!is_directed)
       {
        adjlist[v].push_back(u);
        adjmtx[v][u] = 1;
       }
    }



    void display_nodes()
    {
        for(int i = 0 ; i < nodes.size() ; i++)
        {
            cout << nodes[i].ID <<endl;
            cout << nodes[i].name <<endl;
            cout << nodes[i].blood<<endl;
             cout << nodes[i].address <<endl;
           
        }
        cout << "\n\n\n" ;
    }

    void display_adjlist()
    {
        cout << "                -* LIST *-             " << endl;
        cout << "\n\n";

        for(int i = 0 ; i <adjlist.size() ; i++)
        {
            cout << nodes[i].name << "[" << i << "]" << " -> ";

            for(int j = 0 ; j < adjlist[i].size() ; j++)
            {
                int neighbor = adjlist[i][j] ;
                cout << nodes[neighbor].name << "[" << neighbor <<"] -> " ;
            }

            cout << endl;
        }

        cout << "\n\n\n";

    }



    void display_admtx()
    {
         cout << "                -* MATRIX *-             " << endl;
          cout << "\n\n";
        


          for(int i = 0 ; i < adjmtx.size() ; i++)
          {
            cout <<setw(8) <<  nodes[i].name << " [" << i << "]" ;
            for(int j = 0 ; j < adjmtx[i].size() ; j++)
            {
                cout << "  " << adjmtx[i][j] << " ";
            }
            cout << "\n" ;
          }
        
    
    }
};


int main()
{
    int id ;
    string name , bld , cty;

    int n ;
    cin >> n ;


    human_graph persons(false);

    cout << "Add the persons" <<endl ;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> name >> bld >> cty;

        int id = persons.add_node(name , bld , cty);

    }


    cout << "Add the edges" << endl ;

    while(1)
    {
        cout << "press 1 for adding edges : ";
        int choice ;
        cin >> choice;

        if(choice != 1)
        {
            break;
        }

        int u , v;
        cin >> u >> v ;

        persons.add_edge(u,v);
    }

    persons.display_nodes();
    persons.display_adjlist();
    persons.display_admtx();




}