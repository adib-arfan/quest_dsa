#include<bits/stdc++.h>
using namespace std;

class Graph
{
   public:

   int vertices;
   vector<vector<int>> adjlist;
   vector<int> distance;
   vector<int> parent;

   bool und;


   Graph(int v , bool ud = true): vertices(v) , adjlist(v) , und(ud), distance(v){}

   void add_edge(int u , int v)
   {
    adjlist[u].push_back(v);
    if(und)
    {
        adjlist[v].push_back(u);
    }
   }


   void bfs(int src)
   {
         queue<int> q;
         vector<bool> visited(vertices, false);

         distance.assign(vertices, -1);
         parent.assign(vertices , -1);

         q.push(src);
         visited[src] = true;
         distance[src] = 0;


         while(!q.empty())
         {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for(int v : adjlist[u])
            {
                if(!visited[v])
                {
                    visited[v] = true;
                    distance[v] = distance[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
         }
     }

     void print_shortest_path(int target)
     {
        if(distance[target] == -1)
        {
            cout << "no path exists" << endl;
            return;
        }

        vector<int> path;

        for(int v = target ; v != -1 ; v = parent[v])
        {
            path.push_back(v);
        }
          

        reverse(path.begin() , path.end());


        for(int v : path)
          cout << v << " ";
        
     }
};