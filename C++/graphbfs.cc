#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>graphbfs(int n, vector<vector<int>>& arr){
    vector<int> vis(n+1,0);
    queue<int>q;
    vector<int>bfs_res;

    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                bfs_res.push_back(node);
                for(auto neigh:arr[node]){
                    if(vis[neigh]==0){
                        q.push(neigh);
                        vis[neigh]=1;
                    }
                }
            }
        }
    }
    return bfs_res;
}

vector<int>graphdfs(int n, vector<vector<int>>& arr){
    vector<int> vis(n+1,0);
    vector<int>res;
    auto dfs=[&](auto self,int a)->void{
        res.push_back(a);
        vis[a]=1;
        for(auto i:arr[a]){
            if(vis[i]==0){
                self(self,i);
            }
        }
    };
    for(int i=1;i<=n;i++){
        if(vis[i]==0){dfs(dfs,i);}
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<int>> arr(n+1);
    for(int i=0;i<e;i++){
        int v;
        int u;
        cin>>v;
        cin>>u;
        arr[v].push_back(u);
        arr[u].push_back(v);
    }

    cout<<"DFS traversal"<<endl;
    for(auto i:graphdfs(n,arr)){
        cout<<i<<" ";
    }
cout<<"\n"<<endl;
    cout<<"BFS traversal"<<endl;
    for(auto i:graphbfs(n,arr)){
        cout<<i<<" ";
    }
}