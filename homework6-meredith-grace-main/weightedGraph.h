#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

class WeightedGraph
{
  vector< pair<int,int> >*adjacency_list;
  int vertices;
  public:
  WeightedGraph(int n)
  {
    vertices=n;
    adjacency_list=new vector< pair<int,int> >[n];
  }
  void add_edge(int v1,int v2,int wt);
  void dfsHelper(int src,bool visited[]);
  void dfs(int src);
  void bfs(int src);
  int minDistance(vector<int>dist,bool visited[]);  
  int shortest_path_sum(int** edges_list, int num_nodes);
  void djikstra(int src);
  void display_graph();
};
#endif
