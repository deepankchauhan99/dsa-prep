#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void toposort(vector<vector<pair<int,int>>>& adj,vector<int>& vis, stack<int>& st,int node){
    vis[node]=1;
    for(auto [it,wt]:adj[node]){
        if(!vis[it]){
            toposort(adj,vis,st,it);
        }
    }
    st.push(node);
}


vector<int>shortestPath(int v,vector<vector<int>>edges){
    vector<vector<pair<int,int>>> adj(v);
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }

    stack<int>st;
    vector<int>vis(v);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            toposort(adj,vis,st,i);
        }
    }

    vector<int>dist(v,INT_MAX);
    dist[0]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        for(auto [it,wt]:adj[node]){
            if(dist[it]>dist[node]+wt){
                dist[it]=dist[node]+wt;
            }
        }
    }
    return dist;

}

