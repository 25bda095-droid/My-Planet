#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int> > adj;

    void addedge (int u,int v,bool direction){
        // direction = 0 -> undirected graph
       // direction = 1 -> directed graph

        //create an edge from u to v
        adj[u].push_back(v);

        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void print(){
        for(auto i:adj){
            cout << i.first << "-->";
            for(auto j : i.second){
                cout << j << " ";
            }
        cout<<endl;
        }
    }
};

int main(){
    int k;
    int m;
    int n;
    graph g;
    cout<<"Enter No of connections: ";
    cin>>k;
    cout<<endl;

    for(int i=0;i<k;i++){
        cout<<"Enter edge(m n):";
        cin>>m>>n;
        cout<<endl;
        g.addedge(m,n,0);  // 0 is for undirected graph
    }

    g.print();

}