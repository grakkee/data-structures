//Grace Meredith
//CS 302 Homework #6
//2 May 2021

// NOTE: There is a weird compiling error in my weightedGraph
// that I couldn't figure out (something to do with a vector object I declared)
// So I quickly implemented a simple version of the graph in my main file to achieve what the readme asks

//also my makefile is useless because I did not use the weightedGraph header file in my main driver. 

//#include<weightedGraph.h>

#include <iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

class bruteForce
{
    public:
    int shortest_path_sum(int** edges_list, int num_nodes)
    {
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
    };

    int main()
    {
        /// Getting the number of nodes and number of edges as input
        int num_nodes = 5;
        int num_edges = 8;
        fstream f1, f2;
        /// creating a multi-dimensional array
        int** edges_list = new int*[num_nodes];
        for(int i=0;i<num_nodes;i++)
        {
            edges_list[i] = new int[num_nodes];
            for(int j=0;j<num_nodes;j++)
            {
                edges_list[i][j] = 0;
            }
        }

        f1.open("initialValues.txt", ios::in);
        /// adjacent matrix filling mechanism
        for(int i=0;i<num_edges;i++)
        {
            int first_node,second_node,weight;
            f1 >> first_node >> second_node >> weight;
            edges_list[first_node][second_node] = weight;
            edges_list[second_node][first_node] = weight;

        }
        f1.close();
        f2.open("paths.txt", ios::out);
        f2 << "All Possible Paths: " << endl;
        for(int i=0;i<num_nodes;i++)
        {
            for(int j=0;j<num_nodes;j++)
            {
                f2 << edges_list[i][j] << " ";
            }
            f2 << endl;
        }
        f2 << endl << "Cost of Shortest Path: " << endl;
        bruteForce approach1;
        f2 << approach1.shortest_path_sum(edges_list,num_nodes) << endl;
        f2.close();
        return 0;
    }
