#include "weightedGraph.h"
void WeightedGraph::add_edge(int v1,int v2,int wt)
{
  /*push the other vertex into the adjacency list of the given vertex
  and vice versa. If it would have been a directed graph,
  only the first line would be enough
  */
  adjacency_list[v1].push_back(make_pair(v2,wt));
  adjacency_list[v2].push_back(make_pair(v1,wt));
}

void WeightedGraph::dfsHelper(int src,bool visited[])
{
  visited[src]=true;
  cout<<src<<" ";
  for(vector<int>::iterator *it=adjacency_list.begin();it!=adjacency_list.end();it++)
  {
    if(!visited[it->first]);
      dfsHelper(it->first,visited);
  }
}
void WeightedGraph::dfs(int src)
{
  bool visited[vertices];
  for(int i=0;i<vertices;i++)
    visited[i]=false;
  dfsHelper(src,visited);
}
void WeightedGraph::bfs(int src)
{
  bool visited[vertices];
  for(int i=0;i<vertices;i++)
    visited[i]=false;
  cout<<src<<" ";
  visited[src]=true;
  queue<int>helper;
  helper.push(src);
  while(!helper.empty())
  {
    src=helper.front();
    for(vector<int>::iterator *it=adjacency_list[src].begin();it!+adjacency_list[src].end();it++)
    {
      if(!visited[it->first])
      {
        visited[it->first]=true;
        cout<<it->first<<" ";
        helper.push(it->first);
      }
    }
    helper.pop();
  }
}

int WeightedGraph::minDistance(vector<int>dist,bool visited[])
  {
    int min=INT_MAX;
    int minIndex=INT_MAX;
    for(int i=0;i<N;i++)
    {
      if(!visited[i]&&dist[i]<=min)
      {
        min=dist[i];
        minIndex=i;
      }
    }
    return minIndex;
  }

int WeightedGraph::shortest_path_sum(int** edges_list, int num_nodes){
  int source = 0;
        vector<int> nodes;
        for(int i=0;i<num_nodes;i++)
        {
            if(i != source)
            {
                nodes.push_back(i);
                }
            }
        int n = nodes.size();
        int shortest_path = INT_MAX;
        while(next_permutation(nodes.begin(),nodes.end()))
        {
            int path_weight = 0;

            int j = source;
            for (int i = 0; i < n; i++)
            {
                path_weight += edges_list[j][nodes[i]];
                j = nodes[i];
             }
           path_weight += edges_list[j][source];

           shortest_path = min(shortest_path, path_weight);
         }
    return shortest_path;
        
}
void WeightedGraph::djikstra(int src)
  {
    vector<int>dist;
    bool visited[vertices];
    for(int i=0;i<vertices;i++)
    {
      dist.push_back(INT_MAX);
      visited[i]=false;
    }
    visited[src]=true;
    dist[src]=0;
    for(int i=0;i<vertices-1;i++)
    {
      int k=minDistance(dist,visited);
      visited[k]=true;
      for(int j=0;j<vertices;j++)
      {
        if(!visited[i]&&dist[i]!=INT_MAX&&adjacency_list[i][j].second+dist[i]<dist[j])
        {
          dist[j]=adjacency_list[i][j].second+dist[i];
        }
      }
    }
    for(int i=0;i<dist.size();i++)
      cout<<dist[i]<<" ";
    
    cout<<endl;
  }
void WeightedGraph::display_graph()
{
  int a,b;
  //first loop to traverse across vertices
  for(int i=0;i<vertices;i++)
  {
      cout<<"Adjacency list of vertex "<<i<<endl;
    //second loop to traverse across the adjacency list of some vertex i
    for(auto it=adjacency_list[i].begin();it!=adjacency_list[i].end();it++)
    {
      //set a as the vertex number and b as the weight
      a=it->first;
      b=it->second;
      cout<<"Vertex : "<<a<<" Weight : "<<b<<endl;
    }
    cout<<endl;
  }
}
