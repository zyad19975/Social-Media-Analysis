#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <queue>
#include <iomanip>
using namespace std;


#ifndef GRAPH_H
#define GRAPH_H


#define INFINITY 1000




class Graph
{

private:

    vector<list<pair<int,int>>> adj_list;
    vector<int> nodes_edges;



public:

    Graph(int);
    void read_File(ifstream&);
    void read_File(int);
    void degree_printAll();
    void print_adjacencyList();
    void shortest_Path(int,vector<int>&,vector<int>&);
    void closenessCentrality_printAll();
    void betwenessCentrality_printAll();


};






#endif // GRAPH_H
