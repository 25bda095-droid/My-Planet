#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph{
    public:
    unordered_map<int,,list<int> > adj;

    void addedge (int u,int v , bool direction){
        // direction = 0 ->undirected
        // direction = 1 ->directed graph

        //create an edge from u to v
        adj[u].push_back(v);
    }


};

int main(){

}