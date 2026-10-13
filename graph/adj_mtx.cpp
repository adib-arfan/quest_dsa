#include <iostream>
using namespace std;

class Node
{
    public:

    string name;
    int age;

    Node(){};

    Node(string n , int a)
    {
        name = n;
        age = a;
    }
};


class Graph
{
    int V , E;
    Node* nodes;
    int** adj_mat;

public:

    Graph(int v , int e)
    {
        V = v;
        E = e;
        nodes = new Node[V];


        adj_mat = new int*[V];

        for(int i = 0 ; i < V ; i++)
        {
            adj_mat[i] = new int[V]();
        }
    }


    void read_node()
    {
        for(int i = 0 ; i < V ; i++)
        {
            string n;
            int a;
            cin >> n >> a;
            nodes[i] = Node(n , a);
        }
    }


    void read_edges()
    {
        for(int i = 0 ; i < E ; i++)
        {
            int u, v;
            cin >> u >> v;
            adj_mat[u][v] = 1;
            adj_mat[v][u] = 1;
        }
    }


    void print_graph()
    {
        for(int i = 0 ; i < V ; i++)
        {
            cout << nodes[i].name << "connects to :" << endl ;
            for(int j = 0 ; j < V ; j++)
            {
                if(adj_mat[i][j] == 1)
                {
                    cout << nodes[j].name << endl ;
                }
            }
        }
    }

};

int main()
{
    int V , E ;
    cin >> V >> E ;
    Graph g(V , E);

    g.read_node();
    g.read_edges();
    g.print_graph();

    return 0;
}