#include <bits/stdc++.h>
using namespace std;


class Graph
{
   public:

   int vertices;
   vector<vector<int>> adjlist;
   vector<int> distance;
   vector<int> parent;

   vector<int> visited;

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


   bool cycle_detect_dfs(int src ,vector<int> &visited , vector<int> &parent)
   {
    visited[src] = true;
      for(int v : adjlist[src])
      {
        if()
      }

    }

}; 