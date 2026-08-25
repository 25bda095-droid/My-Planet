#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int> > adj;

    void addedge (int u,int v , bool direction){
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

    // DFS USING STACK for all type graphs connected and disconnected
    // void Dfs(int start,unordered_map<int,bool> &visited){
    //     stack<int>st;
    //     st.push(start);
    //     visited[start]=true;

    //     while(!st.empty()){
    //         int topNode=st.top();
    //         st.pop();

    //         cout<< topNode << " ";

    //         for(auto neighbour: adj[topNode]){
    //             if(!visited[neighbour]){
    //                 visited[neighbour]=true;
    //                 st.push(neighbour);
    //             }
    //         }
    //     }
    // }

    // DFS USING RECURSION (CORRECT WAY OR TO BE USED)
    // Time Complexity is T = O(V+E) (vertex+Edge)
    // Space Complexity = O(V)
        bool Dfs(int node,int parent,unordered_map<int,bool> &visited){
        visited[node]=true;
            cout<< node << " ";

            for(auto neighbour: adj[node]){
              if(!visited[neighbour]){
                   if(Dfs(neighbour,node,visited)){
                    return true;
                    }
                }
                else if(neighbour!=parent){
                    return true;
                }
            }
            return false;
        }

    bool DfsTraversal(){
        unordered_map<int,bool> visited; // it stores thee node visited/unvisited data
        for(auto check: adj){ // we are taking our adj which we have used to store graphs all connected relations like 1 is connected to 2,4
            if(!visited[check.first]){ // we are checking inside the visited if the current node is visited or not
                if(Dfs(check.first,-1,visited)){
                    return true;
                }; // passing values from here 
            }
        }
        return false;
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
    if(g.DfsTraversal()){
        cout<<"cycle is detected";
    }
    else{
        cout<<"No cycle Detected";
    }
    cout<<endl;

    
}