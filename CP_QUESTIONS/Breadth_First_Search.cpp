#include <bits/stdc++.h>
using namespace std;


template<typename T>    // graph to be of generic type
class Graph
{
    map<T, list<T> > l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    // Breadth First Search
    void bfs(T src)
    {
        map<T, bool> visited;
        queue<T> q;

        q.push(src);  // add source node in queue
        visited[src] = true;  // make source note visited

        while(!q.empty())   //  while the queue is not empty
        {
            T node = q.front();  // remove one node from queue
            q.pop();
            cout << node << " ";

            for(T nbr:l[node])  // nbr for neighbour
            {
                if(!visited[nbr])  // check if not visited
                {
                    q.push(nbr);  // push that nbr in queue
                    visited[nbr] = true;  // mark nbr visited 
                }
            }     
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.bfs(0);

    return 0;
}
    
