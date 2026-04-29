#include<iostream>
#include<queue>
#include<vector>


using namespace std;
bool dfs(vector<vector<int>>& graph,vector<int>& vis,int node,int parent){
    vis[node]=1;
    for(auto n:graph[node]){
        if(!vis[n]){if(dfs(graph,vis,n,node))return true;}
        else if(parent!=n)return true;
    }
    return false;
}
bool isCycleUG(vector<vector<int>>& graph){
    int n=graph.size();
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(graph,vis,i,-1))return true;
        }
    }
    return false;
}
bool dfsDG(vector<vector<int>>& graph,vector<int>& vis,vector<int>& path,int node){
    vis[node]=1;
    path[node]=1;
    for(auto n:graph[node]){
        if(!vis[n]){
            if(dfsDG(graph,vis,path,n))return true;
        }
        else if(path[n])return true;
    }
    path[node]=0;
    return false;
}
bool isCycleDG(vector<vector<int>>& graph){
    int n=graph.size();
    vector<int>vis(n,0);
    vector<int>path(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfsDG(graph,vis,path,i))return true;
        }
    }
    return false;
}

int main(){

    vector<vector<int>> ug1 = {
        {1,3},
        {0,2},
        {1,3},
        {2,0}
    };

    vector<vector<int>> ug2 = {
        {1},
        {0,2},
        {1,3},
        {2}
    };

    cout<<"Undirected Graph 1 (Cycle Expected): ";
    if(isCycleUG(ug1)) cout<<"Cycle Present\n";
    else cout<<"No Cycle\n";

    cout<<"Undirected Graph 2 (No Cycle Expected): ";
    if(isCycleUG(ug2)) cout<<"Cycle Present\n";
    else cout<<"No Cycle\n";


    vector<vector<int>> dg1 = {
        {1},
        {2},
        {3},
        {1}
    };

    vector<vector<int>> dg2 = {
        {1,2},
        {3},
        {3},
        {}
    };

    cout<<"Directed Graph 1 (Cycle Expected): ";
    if(isCycleDG(dg1)) cout<<"Cycle Present\n";
    else cout<<"No Cycle\n";

    cout<<"Directed Graph 2 (No Cycle Expected): ";
    if(isCycleDG(dg2)) cout<<"Cycle Present\n";
    else cout<<"No Cycle\n";

    return 0;
}
