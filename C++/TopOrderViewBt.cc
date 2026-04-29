#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include <functional>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x),left(left),right(right){}
};

TreeNode* buildSampleTree(vector<int>nums){
    if(nums.empty()) return nullptr;
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while(i < nums.size()){
        TreeNode* current = q.front();
        q.pop();
        if(nums[i] != -1){
            current->left = new TreeNode(nums[i]);
            q.push(current->left);
        }
        i++;
        if(i < nums.size() && nums[i] != -1){
            current->right = new TreeNode(nums[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

vector<int>topview(TreeNode*root){
    if(!root)return {};
    map<int,pair<int,int>>mp;
    auto dfs=[&](auto self,TreeNode*root,int h,int d)->void{
        if(!root)return;
        
        if(!mp.count(d)||mp[d].first>h) {
            mp[d]={h,root->val};
        }

        self(self,root->left,h+1,d-1);
        self(self,root->right,h+1,d+1);
    };
    dfs(dfs,root,0,0);

    vector<int>res;
    for(auto i:mp){
        res.push_back(i.second.second);
    }
    return res;
} 

vector<int>topviewLV(TreeNode* root){
    if(!root)return {};
    map<int,int>mp;
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        TreeNode*node=temp.first;
        int v=temp.second;
        if(mp.find(v)==mp.end())mp[v]=node->val;
        if(node->left)q.push({node->left,v-1});
        if(node->right)q.push({node->right,v+1});
    }

    vector<int>res;
    for(auto i:mp){
        res.push_back(i.second);
    }
    return res;
}

vector<int>bottomView(TreeNode*root){
    if(!root)return {};
    map<int,pair<int,int>>mp;
    auto dfs=[&](auto self,TreeNode*root,int h,int d)->void{
        if(!root)return;
        
        if(!mp.count(d)||mp[d].first<h) {
            mp[d]={h,root->val};
        }

        self(self,root->left,h+1,d-1);
        self(self,root->right,h+1,d+1);
    };
    dfs(dfs,root,0,0);

    vector<int>res;
    for(auto i:mp){
        res.push_back(i.second.second);
    }
    return res;
} 

vector<int>bottomViewLV(TreeNode*root){
    if(!root)return {};
    map<int,int>mp;
    
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});

    while(!q.empty()){
        auto [node,d]=q.front();
        q.pop();

        mp[d]=node->val;

        if(node->left)q.push({node->left,d-1});
        if(node->right)q.push({node->right,d+1});
    }

    vector<int>res;
    for(auto i:mp){
        res.push_back(i.second);

    }
    return res;
}

vector<int>rightSideView(TreeNode*root){
    if(!root)return {};
    vector<int>res;
    auto dfs=[&](auto self,TreeNode*root,int h)->void{
        if(!root)return;
        if(res.size()==h)res.push_back(root->val);

        self(self,root->right,h+1);
        self(self,root->left,h+1);
    };
    dfs(dfs,root,0);
    return res;
}

vector<int>rightSideViewLV(TreeNode*root){
    if(!root)return {};

    int depth=0;
    vector<int>res;

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        int n=q.size();
        res.push_back(q.front()->val);
        while(n--){
            TreeNode*node=q.front();
            q.pop();

            res.back()=node->val;

            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        depth++;
    }
    return res;
}

vector<int>leftSideView(TreeNode*root){
    if(!root)return {};
    vector<int>res;
    auto dfs=[&](auto self,TreeNode*root,int h)->void{
        if(!root)return;
        if(res.size()==h)res.push_back(root->val);

        self(self,root->left,h+1);
        self(self,root->right,h+1);
    };
    dfs(dfs,root,0);
    return res;
}

vector<int>leftSideViewLV(TreeNode*root){
    if(!root)return {};

    vector<int>res;

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        int n=q.size();
        res.push_back(q.front()->val);
        while(n--){
            TreeNode*node=q.front();
            q.pop();

            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
    }
    return res;
}

bool isSymetric(TreeNode*root){
    if(!root)return true;
    auto dfs=[&](auto self,TreeNode*p,TreeNode*q)->bool{
        if(!p||!q)return p==q;

        return ((p->val==q->val)&&(self(self,p->left,q->right))&&(self(self,p->right,q->left)));
    };
    return dfs(dfs,root->left,root->right);
}

int main(){
    vector<int>nums={1,2,3,4,5,6,-1,-1,-1,7,8,9,10,-1,-1,11,12};
    TreeNode*root=buildSampleTree(nums);
    // vector<int>r=topviewLV(root);
    // vector<int>t=bottomView(root);
    vector<int>t=rightSideView(root);
    vector<int>y=rightSideViewLV(root);
    vector<int>u=leftSideView(root);
    vector<int>a=leftSideViewLV(root);

    for(auto i:a){
        cout<<i<<" ";
    }
    cout<<"\n"<<endl;
    for(auto i:u){
        cout<<i<<" ";
    }
    return 0;
}


