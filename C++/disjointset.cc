#include<iostream>
#include<vector>

using namespace std;

class DisjointSet{
    vector<int> rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1);
        parent.resize(n+1);
        size.resize(n+1,1);

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
        int uparent=findParent(u);
        int vparent=findParent(v);

        if(uparent==vparent)return;

        if(rank[uparent]>=rank[vparent]){
            rank[uparent]=rank[uparent]==rank[vparent]?rank[uparent]+1:rank[uparent];
            parent[vparent]=uparent;
        }
        else{
            parent[uparent]=vparent;
        }
    }

    void unionBySize(int u,int v){
        int up=findParent(u);
        int vp=findParent(v);

        if(up==vp)return;

        if(size[vp]>size[up]){
            parent[up]=vp;
            size[vp]+=size[up];
        }else{
            parent[vp]=up;
            size[up]+=size[vp];
        }
    }
};


int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(5,6);
    ds.unionByRank(6,7);

    if(ds.findParent(3)==ds.findParent(7))cout<<"same parent bhadwe"<<endl;
    else {cout<<"not same parent bhokat jaa"<<endl;}
    ds.unionByRank(3,7);

    cout<<"lund pna krne ke baad"<<endl;

    if(ds.findParent(3)==ds.findParent(7))cout<<"same parent bhadwe"<<endl;
    else {cout<<"not same parent bhokat jaa"<<endl;}

    return 0;
}