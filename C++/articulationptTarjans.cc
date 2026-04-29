#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int>>&adj,vector<int>&vis,vector<int>&tin,vector<int>&low,int&time,int parent,int node,int&cnt,vector<int>&res){
    vis[node]=1;
    tin[node]=time;
    low[node]=time;
    time++;
    
    int count=0;

    for(auto it:adj[node]){
     if(it == parent) continue;
        if(!vis[it]){
            count++;

            dfs(adj, vis, tin, low, time, node, it, cnt,res);

            low[node] = min(low[node], low[it]);

            // Bridge condition
            if(low[it] >= tin[node]&&parent!=-1){
                res[node]=1;
            }
        }
        else{
            low[node] = min(low[node], tin[it]);
        }
    }
    if(parent==-1&&count>1)res[node]=1;
}

vector<int> articulationTarjan(vector<vector<int>>&adj,int n){
    vector<int>vis(n);
    vector<int>tin(n);
    vector<int>low(n);
    vector<int>res(n);
    int time=1;
    int cnt=1;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(adj,vis,tin,low,time,-1,i,cnt,res);
        }
    }
    
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(res[i])ans.push_back(i);
    }

    return ans;
}


int main(){
    int n = 10;
    vector<vector<int>> adj(n);

    // Component 1
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(0);
    adj[0].push_back(2);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[4].push_back(5);
    adj[5].push_back(4);

    // Component 2
    adj[6].push_back(7);
    adj[7].push_back(6);

    adj[7].push_back(8);
    adj[8].push_back(7);

    adj[8].push_back(6);
    adj[6].push_back(8);

    adj[8].push_back(9);
    adj[9].push_back(8);

    vector<int> ap = articulationTarjan(adj, n);

    cout << "Articulation Points:\n";
    for(auto it : ap){
        cout << it << " ";
    }

    return 0;
}