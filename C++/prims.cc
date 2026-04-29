#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

vector<vector<pair<int,int>>>prims(vector<vector<pair<int,int>>>adj,int n){
    vector<vector<pair<int,int>>>mst(n);//{node -> nei , wt}
    vector<int>vis(n);

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;//{wt,node,parent}
    pq.push({0,0,-1});

    while(!pq.empty()){
        auto [wt,node,parent]=pq.top();
        pq.pop();

        if(vis[node])continue;
        
        vis[node]=1;

        if(parent!=-1){
            mst[node].push_back({wt,parent});
            mst[parent].push_back({wt,node});
        }

        for(auto [nei,w]:adj[node]){
            if(!vis[nei]){
                pq.push({w,nei,node});
            }
        }
    }
    return mst;

}

int main(){
    int n = 5;
    vector<vector<pair<int,int>>> edges(n);

    // Undirected graph
    edges[0].push_back({1, 2});
    edges[1].push_back({0, 2});

    edges[0].push_back({3, 6});
    edges[3].push_back({0, 6});

    edges[1].push_back({2, 3});
    edges[2].push_back({1, 3});

    edges[1].push_back({3, 8});
    edges[3].push_back({1, 8});

    edges[1].push_back({4, 5});
    edges[4].push_back({1, 5});

    edges[2].push_back({4, 7});
    edges[4].push_back({2, 7});

    auto mst = prims(edges, n);

    cout << "Minimum Spanning Tree: PRIMS \n";
    int totalWeight = 0;

    for(int i = 0; i < n; i++){
        for(auto [wt, nei] : mst[i]){
            if(i < nei){ // avoid duplicate printing
                cout << i << " - " << nei << " : " << wt << "\n";
                totalWeight += wt;
            }
        }
    }

    cout << "PRIMS Total Weight: " << totalWeight << "\n";

    return 0;
}