#include <bits/stdc++.h>
using namespace std;

class Graph
{
   int V;
   vector<list<int>> adj_list;
   bool undirected;

   public:

   Graph(bool ud , int vertices) : undirected(ud) , V(vertices) , adj_list(V){}

   void add_edge(int u , int v)
   {
    adj_list[u].push_back(v);
     
      if(undirected)
      {
        adj_list[v].push_back(u);
      }

   }

   void print()
   {
    for(int u = 0 ; u < V ; u++)
    {
        cout << u << " -> ";

        for(int v : adj_list[u])
        {
            cout << v << " ";
        }
        cout << "\n";
    }
   }


   void bfs(int src)
   {
        queue<int> q;
        vector<bool> visited(V , false);
        q.push(src);
        

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            visited[u] = true;

            cout << u << " " ;

            for(int v : adj_list[u])
            {
                if(!visited[v])
                {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        cout << "\n" ;
   }
   
   
   
};