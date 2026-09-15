#include<iostream>
#include<vector>

using namespace std;

struct segmenttree{
    vector<int>st;
    int n=0;

    void init(int n){
        this->n=n;
        st.resize(4*n);
    }

    void update(int start,int end,int index,int val,int node){
        if(start==end){
            st[node]=val;
            return;
        }
        int mid=start+end;
        mid/=2;
        if(index<=mid){
            update(start,mid,index,val,2*node+1);
        }else {
            update(mid+1,end,index,val,2*node+2);
        }
        st[node]=st[2*node+1]+st[2*node+2];
    }
    void update(int val,int index){
        update(0,n-1,index,val,0);
    }

    void build(int start,int end,int node,vector<int>&v){
        if(start==end){
            st[node]=v[start];
            return;
        }
        int mid=start+end;
        mid/=2;

        build(start,mid,2*node+1,v);

        build(mid+1,end,2*node+2,v);

        st[node]=st[2*node+1]+st[2*node+2];
    }
    void build(vector<int> v){
        build(0,v.size()-1,0,v);
    }

    int query(int start,int end,int l,int r,int node){
        int mid=start+end;
        mid/=2;
        // no overlap
        if(l>end||r<start){
            return 0;
        }
        //complete overlap
        else if(l<=start&&r>=end){
            return st[node];
        }
        int res=query(start,mid,l,r,2*node+1);
        res+=query(mid+1,end,l,r,2*node+2);

        return res;
    }

    int query(int l,int r){
        return query(0,n-1,l,r,0);
    }
};

int main(){

    vector<int>v={1,2,3,4,5,6,7,8,9};
    segmenttree tree;
    tree.init(v.size());
    tree.build(v);
    cout<<tree.query(0,4)<<endl;
    tree.update(90,4);
    cout<<tree.query(0,6)<<endl;
    cout<<tree.query(0,4)<<endl;
    tree.update(-4,3);
    cout<<tree.query(3,4)<<endl;
    return 0;
}