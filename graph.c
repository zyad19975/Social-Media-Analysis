
#include "graph.h"


Graph::Graph(int number_nodes)
{

    adj_list.resize(number_nodes);
    nodes_edges.resize(number_nodes,0);


}

void Graph::read_File(ifstream& myFile)
{

    int node,adjacent_node,edge_weight;

    while(!(myFile.eof()))
    {
        myFile>>node>>adjacent_node>>edge_weight;

        adj_list[node].push_back({adjacent_node,edge_weight});
        adj_list[adjacent_node].push_back({node,edge_weight});
        nodes_edges[node]++;
        nodes_edges[adjacent_node]++;
    }


}

void Graph::read_File(int number_edges)
{

    int node,adjacent_node,edge_weight;

    while(number_edges--)
    {
        cin>>node>>adjacent_node>>edge_weight;

        adj_list[node].push_back({adjacent_node,edge_weight});  
        adj_list[adjacent_node].push_back({node,edge_weight});  
        nodes_edges[node]++;
        nodes_edges[adjacent_node]++;
        
    }

}



void Graph::degree_printAll()
{
    for(int i=0;i<nodes_edges.size();i++)
            cout<<nodes_edges[i]<<endl;
}

