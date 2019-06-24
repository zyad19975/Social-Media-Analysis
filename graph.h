#include <iostream>
#include <list>
#include <vector>
#include <fstream>

using namespace std;


#ifndef GRAPH_H
#define GRAPH_H





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
    void closenessCentrality_printAll();
    void betwenessCentrality_printAll();


};






#endif // GRAPH_H
