
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

void Graph::print_adjacencyList()
{
    
    
    for(int i=0;i<adj_list.size();i++)
    {
        list<pair<int,int> >::iterator it;

        for(it=adj_list[i].begin();it!=adj_list[i].end();it++)
        {

                cout<<i<<"=="<<it->second<<"==>"<<it->first<<endl;
        }
    }

    
}


void Graph::shortest_Path(int source,vector<int>& shortest_distances,vector<int>& parents)
{
    
    //pair (distance , node)
    priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> p_queue;
    
    p_queue.push({{0,source},source});
    shortest_distances[source]=0;
    parents[source]=source;
    
    
    list<pair<int,int>>::iterator it;
    
    while(!(p_queue.empty()))
    {
        
        int next_node=p_queue.top().first.second;
        int accumlative_distance=p_queue.top().first.first;
        int parent=p_queue.top().second;
        p_queue.pop();
    
    
    if(shortest_distances[next_node] == INFINITY)
    {
        
        shortest_distances[next_node]=accumlative_distance;
        parents[next_node]=parent;
    }
        
        
        for(it=adj_list[next_node].begin();it!=adj_list[next_node].end();it++)
        {
            
            
            int adj_node= it->first;
            int adj_node_weight=it->second;
            
            
            
            
            if(shortest_distances[adj_node] == INFINITY)
            {
                
                p_queue.push({{adj_node_weight+accumlative_distance,adj_node},next_node});
                
            }
            
            
        }
        
        
        
    }
    
}



void Graph::closenessCentrality_printAll()
{
    int size=adj_list.size();
    int sum;
    
    for(int i=0;i<size;i++)
    {
    
    sum=0;
    vector<int> shortest_distances(size,INFINITY);
    vector<int> parents(size,-1);

    shortest_Path(i,shortest_distances,parents);
    
    for(int j=0;j<size;j++)
    {
        sum+=shortest_distances[j];
    }
    
    cout<<setprecision(9)<<((float)(size-1))/sum<<endl;
    
    
    }
    
}