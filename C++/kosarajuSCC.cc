#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//1. find out starting points in stack (dfs)

//2. reverse the edges

//3. dfs on starting points with visited marking

void dfs1(vector<vector<int>>&adj,vector<int>&vis,vector<int>&st,int node){
    vis[node]=1;

    for(auto it:adj[node]){
        if(!vis[it]){
            dfs1(adj,vis,st,it);
        }
    }
    st.push_back(node);
}

void dfs2(vector<vector<int>>&adjT,vector<int>&vis,vector<int>&comp,int node){
    vis[node]=1;
    comp.push_back(node);

    for(auto it:adjT[node]){
        if(!vis[it]){
            dfs2(adjT,vis,comp,it);
        }
    }
}

// kosaraju algorithm
vector<vector<int>>connectedComponents(vector<vector<int>>&adj,int n){
    vector<int>vis(n);
    vector<int>st;

    for(int i=0;i<n;i++){
    if(!vis[i]){
        dfs1(adj,vis,st,i);
    }
}
    vector<vector<int>>adjT(n);
    for(int i=0;i<n;i++){
        vis[i]=0;
        for(auto it:adj[i]){
            adjT[it].push_back(i);
        }
    }

    vector<vector<int>>res;
    while(!st.empty()){
        int node=st.back();
        st.pop_back();

        if(!vis[node]){
            vector<int>comp;
            dfs2(adjT,vis,comp,node);
            res.push_back(comp);
        }
    }
    return res;
}

int main(){
    int n = 6;
    vector<vector<int>> adj(n);

    // SCC 1
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);

    // connection to another component
    adj[1].push_back(3);

    // SCC 2
    adj[3].push_back(4);
    adj[4].push_back(5);
    adj[5].push_back(3);

    vector<vector<int>> scc = connectedComponents(adj, n);

    cout << "Strongly Connected Components:\n";
    for(auto comp : scc){
        for(auto node : comp){
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}