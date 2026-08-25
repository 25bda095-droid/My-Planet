#include <iostream>
#include <unordered_map>
#include <list>
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

    //This is For Single graph like all the nodes are connected it will not work for multiple graph if present which are not connected
    // void bfs(int start){
    // queue<int> q; //queue is defined

    // unordered_map<int,bool> visited; //to store which neighbours we have visited or not

    // q.push(start); //we will push our first node

    // visited[start] = true; // we will give true values to already visited node so it didnot repeat

    // while(!q.empty()) 
    // {
    //     int frontNode = q.front(); //this gives us first node but didnot remove it from queue

    //     q.pop(); // we remove the first node using pop

    //     cout << frontNode << " "; //printing the nodes

    //     for(auto neighbour : adj[frontNode]) // using the for loop to see the adj neighbours of each nodes
    //     {
    //         if(!visited[neighbour]) // if the neighbour is false we will add it in queue
    //             {
    //                 visited[neighbour] = true; // if not visited we mark it visited

    //                 q.push(neighbour); // then we store it in queue
    //             }
    //         }
    //     }
    // }

    // For Multiple Graphs or single both(works for all if all coonnected or not it does not matter here)
    // Time Complexity is T(V+E)
    // Space=O(V)
    void bfs(int start,unordered_map<int,bool> &visited){
        queue<int> q;

        q.push(start);
        visited[start]=true;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            cout<< front << " ";

            for(auto neighbour: adj[front]){
                if(!visited[neighbour]){
                    
                    visited[neighbour]=true;
                    q.push(neighbour);
                }
            }
        }
        cout<<endl;
    }

    bool cycledetection(int start,unordered_map<int,bool> &visited){
    queue<pair<int,int>> q;
    q.push({start,-1});
    visited[start]=true;

    while(!q.empty()){
        int currentnode=q.front().first;
        int parent=q.front().second;
        q.pop();

        for(auto neighbour: adj[currentnode]){
            if(!visited[neighbour]){
                
                visited[neighbour]=true;
                q.push({neighbour,currentnode});
            }
            else if(neighbour!=parent){
                return true;
            }
            }
        }
         return false;
    }

    void BfsTraversal(){
        unordered_map<int,bool> visited; // it stores thee node visited/unvisited data
        for(auto check: adj){ // we are taking our adj which we have used to store graphs all connected relations like 1 is connected to 2,4
            if(!visited[check.first]){ // we are checking inside the visited if the current node is visited or not
                bfs(check.first,visited); // passing values from here 
            }
        }
    }
        bool CycleTraversal(){
        unordered_map<int,bool> visited; // it stores thee node visited/unvisited data
        for(auto check: adj){ // we are taking our adj which we have used to store graphs all connected relations like 1 is connected to 2,4
            if(!visited[check.first]){ // we are checking inside the visited if the current node is visited or not
                if(cycledetection(check.first,visited)){
                    return true;
                } // passing values from here 
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
    g.BfsTraversal();
    if(g.CycleTraversal()){
        cout<<"Cycle is detected";
    }
    else{
        cout<<"Cycle is not Detected";
    }
    cout<<endl;
}


