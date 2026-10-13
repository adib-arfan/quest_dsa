#include <bits/stdc++.h>
using namespace std;

class Graph
{
    public:

    vector<vector<int>> adj_list;

    vector<int> bfs_trav;

   
    int vertices;

    Graph(int v ): vertices(v)  , adj_list(v){}


  
  
  
    void add_edge(int u , int v)
    {
         adj_list[u].push_back(v);
         adj_list[v].push_back(u);
    }



   
   
    void bfs(int src)
    {
        vector<bool> visited(vertices , false);
        queue<int> que;

        que.push(src);
         visited[src] = true;

        while(!que.empty())
        {
            int u = que.front();
            que.pop();

           
            bfs_trav.push_back(u);

            for(int v : adj_list[u])
            {
                if(!visited[v])
                {
                    visited[v] = true;
                    que.push(v);
                }
            }
        }
    }







    
};









int main()
{
 Graph gg(11);

    gg.add_edge(1,2);
    gg.add_edge(1,4);
    gg.add_edge(4,3);
    gg.add_edge(2,3);
    gg.add_edge(3,10);
    gg.add_edge(3,9);
    gg.add_edge(2,5);
    gg.add_edge(2,7);
    gg.add_edge(2,8);
    gg.add_edge(5,8);
    gg.add_edge(5,7);
    gg.add_edge(8,7);
    gg.add_edge(5,6);



    gg.bfs(1);



    for(int x : gg.bfs_trav)
       cout << x << "  " ;
    
}