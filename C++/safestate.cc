#include<iostream>
#include<vector>

using namespace std;


bool dfs(vector<vector<int>>& graph,vector<int>&vis,vector<int>&path,vector<int>& check,int node){
    vis[node]=1;
    path[node]=1;
    check[node]=0;//unsafe node default
    for(auto n:graph[node]){
        if(!vis[n]){
            if(dfs(graph,vis,path,check,n))return true;
        }
        else if(path[n])return true;
        else if(!check[n])return true;
    }

    path[node]=0;
    check[node]=1;//safe
    return false;
}

vector<int> safenodes(vector<vector<int>>& graph){
    int n=graph.size();
    vector<int>vis(n,0);
    vector<int>path(n,0);
    vector<int>check(n,0);
    vector<int>safeNode;

    for(int i=0;i<n;i++){
        if(!vis[i])dfs(graph,vis,path,check,i);
    }

    for( int i=0;i<check.size();i++){
        if(check[i])safeNode.push_back(i);
    }
    return safeNode;
}

int main(){

    // 0 → 1 → 2 → 3
    //       ↑     ↓
    //       ← ← ←
    // 4 → 5  (safe chain)
    vector<vector<int>> dg1 = {
        {1},    // 0
        {2},    // 1
        {3},    // 2
        {1},    // 3  cycle
        {5},    // 4
        {}      // 5
    };

    vector<vector<int>> dg2 = {
        {1,2},  // 0
        {3},    // 1
        {3},    // 2
        {}      // 3
    };

    vector<int> safe1 = safenodes(dg1);
    vector<int> safe2 = safenodes(dg2);

    cout<<"Graph 1 Safe Nodes: ";
    for(auto x : safe1) cout<<x<<" ";
    cout<<"\n";

    cout<<"Graph 2 Safe Nodes: ";
    for(auto x : safe2) cout<<x<<" ";
    cout<<"\n";

    return 0;
}
