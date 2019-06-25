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
    
    
    //cin>>total_nodes>>total_edges;
    myFile>>total_nodes>>total_edges;


    Graph myGraph(total_nodes);
    
    
    
    
    myGraph.read_File(myFile);
    //myGraph.read_File(total_edges);
    
    
    cout<<"Centriality"<<endl;
    myGraph.degree_printAll();


    cout<<"Closeness-Centriality"<<endl;
    myGraph.closenessCentrality_printAll();






    return 0;
}





