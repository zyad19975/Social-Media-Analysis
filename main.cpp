#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include "graph.h"
using namespace std;




int main()
{

    int total_nodes=0,total_edges=0;
    
    
    ifstream myFile("input_data.txt");
    myFile>>total_nodes>>total_edges;
    //cin>>total_nodes>>total_edges;



    Graph myGraph(total_nodes);
    
    
    
    myGraph.read_File(myFile);
    //myGraph.read_File(total_edges);
    myGraph.degree_printAll();







    return 0;
}





