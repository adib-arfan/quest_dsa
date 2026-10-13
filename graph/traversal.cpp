#include <bits/stdc++.h>
using namespace std;

class graph
{
      public:
    vector<vector<int>> adj_list;
    vector<vector<int>> adj_matrix;
    bool undirected;
    int vertices;

  

    graph(bool undirected = true , int v = 0):vertices(v) ,adj_list(v)  , adj_matrix(v , vector<int>(v ,0)) , undirected(undirected){}
        
 


    void add_edge(int u , int v)
    {
        adj_list[u].push_back(v);
        adj_matrix[u][v] = 1;

        if(undirected)
        {
              adj_list[v].push_back(u);
              adj_matrix[v][u] = 1;
        }
    }


    void print()
    {
         for(int u = 0 ; u < adj_list.size() ; u++)
         {
            cout << u << " -> " ;

            for(int v : adj_list[u])
            {
                cout << v << " "; 
            }

            cout << "\n";
         }


         cout <<"\n\n\n";

         for(int u = 0 ; u < adj_matrix.size() ; u++)
         {
            cout << setw(8) << "[" << u << "] ";

            for(int v = 0 ; v < adj_matrix.size() ; v++)
            {
                cout << setw(8) << adj_matrix[u][v] ;
            }
            cout <<"\n";
         }
    }


    void bfs(int src)
    {
        queue<int> q;
        vector<bool> visited(vertices, false);
       
        q.push(src);

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            visited[u] = true;

            cout <<u<<" -----> ";

            for(int v : adj_list[u])
            {
                if(!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

       cout << "\n\n";

        vector<int> visited2(vertices , false);
        queue<int> q2;

        q2.push(src);
        
        int count = 5;

        while(!q2.empty())
        {

            if(count == 0)
            break;

            int u = q2.front();
            q2.pop();

             cout <<u<<" -----> ";

            visited2[u] = true;

            for(int v = 0 ; v < vertices ; v++)
            {
                if(adj_matrix[u][v] == 1  && !visited2[v] )
                {
                    q2.push(v);
                }
            }

            count--;
        }
        
        
    }





    void dfs_list(int src , vector<bool> &visited)
    {
        cout << src << " -> ";
        visited[src] = true;

        for(int v : adj_list[src])
        {
            if(!visited[v])
            {
                dfs_list(v , visited);
            }
        }
    }


    void dfs_mtrx(int src , vector<bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;

        for(int v = 0 ; v < vertices ; v++)
        {
            if(adj_matrix[src][v] == 1 && !visited[v])
            {
                dfs_mtrx(v , visited);
            }
        }
    }

};


int main()
{
    int V;
    cin >> V;
    int u , v;

    graph g(true , V);

    while(1)
    {
        int c;
        cin >> c;

        if(c == 0)
           break;

        cin >> u >> v ;
        g.add_edge(u ,v);
    }

    g.print();


    cout << "\n\n";
    // g.bfs(0);

    vector<bool> visited(g.vertices , false);

    // g.dfs_list(0, visited);
    g.dfs_mtrx(0 , visited);
}
