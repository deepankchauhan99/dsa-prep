#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){
    int n=graph.size();
    vector<int>vis(n,0);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i])dfs(graph,vis,st,i);
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    return 0;
}

void dfs(vector<vector<int>>& graph,vector<int>& vis,stack<int>& st,int node){
    vis[node]=1;
    for(auto n:graph[node]){
        if(!vis[n])dfs(graph,vis,st,n);
    }
    st.push(node);
}