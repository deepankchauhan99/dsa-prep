#include<iostream>
#include<vector>
// #include<

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr[n];
    for(int i=0;i<n;i++){
        int v;
        int u;
        cin>>v;
        cin>>u;
        arr[v].push_back(u);
        arr[u].push_back(v);
    }

    int vis[n];
    queue<int>q;
    q.push(1);
    vis[1]=1;

    vector<int>bfs_res;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs_res.push_back(node);
        for(auto i:arr[node]){
            if(vis[i]==0){
                q.push(i);
                vis[i]=1;
            }
        }
    }

    cout<<"BFS traversal"<<endl;
    for(auto i:bfs_res){
        cout<<i<<" ";
    }
}