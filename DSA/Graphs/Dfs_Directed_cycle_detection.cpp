#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph{
public:

    unordered_map<int, list<int>> adj;

    void addedge(int u, int v, bool direction){
        // direction = 1 for directed graph

        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void print(){
        for(auto i : adj){
            cout << i.first << " --> ";

            for(auto j : i.second){
                cout << j << " ";
            }

            cout << endl;
        }
    }

    bool Dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &pathVisited)
    {
        // Step 1: Mark visited
        visited[node] = true;

        // Step 2: Mark current recursion path
        pathVisited[node] = true;

        // Step 3: Traverse all neighbours
        for(auto neighbour : adj[node])
        {
            // If neighbour is not visited
            if(!visited[neighbour])
            {
                if(Dfs(neighbour, visited, pathVisited))
                {
                    return true;
                }
            }

            // If neighbour is already in current recursion path
            else if(pathVisited[neighbour])
            {
                return true;
            }
        }

        // Step 4: Remove current node from recursion path
        pathVisited[node] = false;

        return false;
    }

    bool DfsTraversal()
    {
        unordered_map<int,bool> visited;
        unordered_map<int,bool> pathVisited;

        for(auto check : adj)
        {
            if(!visited[check.first])
            {
                if(Dfs(check.first, visited, pathVisited))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    graph g;

    int edges;
    cout << "Enter number of edges : ";
    cin >> edges;

    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin >> u >> v;

        g.addedge(u,v,1);   // Directed Graph
    }

    g.print();

    if(g.DfsTraversal())
    {
        cout << "Cycle Detected";
    }
    else
    {
        cout << "No Cycle Detected";
    }
}