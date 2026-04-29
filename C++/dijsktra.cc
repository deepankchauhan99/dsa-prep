#include <iostream>
#include<vector>
#include<queue>
using namespace std;

// adj
// node-a -> {node-b,wt}

vector<int> dijkstra(vector<vector<pair<int,int>>>&adj,int n,int src){
    vector<int>dis(n,1e9);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // wt -> node
    dis[src]=0;
    pq.push({0,src});

    while(!pq.empty()){
        auto [wt,node]=pq.top();
        pq.pop();

        if(dis[node]<wt)continue;
        for(auto [nei,w]:adj[node]){
            if(dis[nei]>dis[node]+w){
                dis[nei]=dis[node]+w;
                pq.push({dis[nei],nei});
            }
        }
    }
    return dis;
}



int main(){
    int n = 5; // number of nodes
    vector<vector<pair<int,int>>> adj(n);

    // Sample graph (undirected)
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({2, 4});
    adj[2].push_back({0, 4});

    adj[1].push_back({2, 1});
    adj[2].push_back({1, 1});

    adj[1].push_back({3, 7});
    adj[3].push_back({1, 7});

    adj[2].push_back({4, 3});
    adj[4].push_back({2, 3});

    adj[3].push_back({4, 1});
    adj[4].push_back({3, 1});

    int src = 0;

    vector<int> result = dijkstra(adj, n, src);

    cout << "Shortest distances from node " << src << ":\n";
    for(int i = 0; i < n; i++){
        cout << "Node " << i << " -> " << result[i] << "\n";
    }

    return 0;
}


