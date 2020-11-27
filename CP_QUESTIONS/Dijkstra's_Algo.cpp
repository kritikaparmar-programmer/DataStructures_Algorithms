#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    unordered_map<T, list<pair<T, int>>> m;  // hashmap

public:

    void addEdge(T u, T v, int dist, bool bidir=true)  // bidirectional
    {
        m[u].push_back(make_pair(v, dist));
        if(bidir)
        {
            m[v].push_back(make_pair(u, dist));
        }
    }

    void print_Adj_list()
    {
        // iterate over all key, value pairs in map
        for(auto j:m)
        {
            cout << j.first << "-> ";
            for(auto l:j.second)
            {
                cout << "(" << l.first << ", " << l.second << ")";
            }
            cout << endl;
        }
    }

    void dijkstra(T src)
    {
        unordered_map<T, int> dist;      // Ex - (Mumbai, 2)

        // set all distance to infinity
        for(auto j:m)
        {
            dist[j.first]  = INT_MAX;    // dist[city] = infinity
        }

        // make a set to find out node with minimum distance
        set<pair<int, T>> s;             // (dist, city), as set sorts acc to first parameter

        dist[src] = 0;
        s.insert(make_pair(0, src));

        while(!s.empty())
        {

            // find pair at front
            auto p = *(s.begin());      // s.begin() is a pointer to first and star of that will give the value of pair
            T node = p.second;          // node = city

            int nodeDist = p.first;     // distance of parent
            s.erase(s.begin());         // like pop in queue

            // iterate over neighbours of current node
            for(auto childPair: m[node])
            {
                if(nodeDist + childPair.second < dist[childPair.first])
                {
                    // in set updation of a particular node is not possible 
                    // so remove old pair & insert new pair for updation
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if(f != s.end())
                    {
                        s.erase(f);
                    }

                    // insert new pair
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest], dest));

                }
            }   
        }

        // print distance from src
        for(auto d:dist)
        {
            cout << d.first << " is located at distance of " << d.second << " from source." << endl;
        }
    }
};

int main()
{

    Graph<int> g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 4, 7);
    g.print_Adj_list();
    cout << endl;
    g.dijkstra(1);

    cout << endl;

    Graph<string> india;
    india.addEdge("Amritsar", "Delhi", 1);
    india.addEdge("Amritsar", "Jaipur", 4);
    india.addEdge("Jaipur", "Delhi", 2);
    india.addEdge("Jaipur", "Mumbai", 8);
    india.addEdge("Bhopal", "Agra", 2);
    india.addEdge("Mumbai", "Bhopal", 3);
    india.addEdge("Agra", "Delhi", 1);
    india.print_Adj_list();
    cout << endl;
    india.dijkstra("Amritsar");

    return 0;
}