#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int>>&adj,vector<int>&vis,vector<int>&timevec,vector<int>&mintime,int&time,int parent,int node,int&cnt){
    vis[node]=1;
    timevec[node]=time;
    mintime[node]=time;
    time++;

    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(adj,vis,timevec,mintime,time,node,it,cnt);
        }
    }
    for(auto it:adj[node]){
        if(it!=parent){
            if(mintime[it]<mintime[node])mintime[node]=mintime[it];
            else if(mintime[it]>timevec[node]){cnt++;}//add edge 
        }
    }
}

int tarjans(vector<vector<int>>&adj,int n){
    vector<int>vis(n);
    vector<int>timevec(n);
    vector<int>mintime(n);
    int time=1;
    int cnt=1;
    dfs(adj,vis,timevec,mintime,time,-1,0,cnt);
    return cnt;
}


int main(){

}