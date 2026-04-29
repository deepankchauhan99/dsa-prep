#include<iostream>
#include<vector>
#include<tuple>

using namespace std;

class DisjointSet{
    vector<int>rank,parent;

    public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }

    void unionByRank(int u,int v){
        int u_parent=findParent(u);
        int v_parent=findParent(v);

        if(u_parent==v_parent)return;

        if(rank[u_parent]>=rank[v_parent]){
            rank[u_parent]=rank[u_parent]==rank[v_parent]?rank[u_parent]+1:rank[u_parent];
            parent[v_parent]=u_parent;
        }
        else{
            parent[u_parent]=v_parent;
        }
    }
};

// adj node->{nei,wt}
vector<vector<pair<int,int>>>kruskal(vector<vector<pair<int,int>>>&adj,int n){
    vector<tuple<int,int,int>>edges;
    for(int i=0;i<n;i++){
        for(auto[nei,wt]:adj[i]){
            edges.push_back({wt,i,nei});
        }
    }
    vector<vector<pair<int,int>>>mst(n);
    DisjointSet ds(n);
    sort(edges.begin(),edges.end());
    for(auto [wt,u,v]:edges){
        if(ds.findParent(u)!=ds.findParent(v)){
            mst[u].push_back({v,wt});
            mst[v].push_back({u,wt});
            ds.unionByRank(u,v);
        }
    }
    return mst;
}

int main(){
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);

    // Add edges (u, v, weight)
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    // Run Kruskal
    vector<vector<pair<int,int>>> mst = kruskal(adj, n);

    // Print MST
    cout << "MST Edges KRUSKAL :\n";
    int totalWeight=0;
    for(int i = 0; i < n; i++){
        for(auto [nei, wt] : mst[i]){
            if(i < nei) { // avoid duplicate print
                cout << i << " - " << nei << " : " << wt << "\n";
                totalWeight += wt;
            }
        }
    }
    cout << "KRUSKAL Total Weight: " << totalWeight << "\n";

    return 0;
}