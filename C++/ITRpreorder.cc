#include<iostream>
#include<stack>
#include<queue>

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


vector<int> iterative_preorder(TreeNode*root){
    if(!root)return {};
    vector<int>res;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode*temp=st.top();
        st.pop();
        res.push_back(temp->val);
        if(temp->right)st.push(temp->right);
        if(temp->left)st.push(temp->left);
    }
    return res;
}

vector<int> iterative_inorder(TreeNode* root){
    if(!root)return{};
    vector<int>res;
    stack<TreeNode*>st;
    TreeNode* temp=root;
    while(temp||!st.empty()){
        while(temp){
            st.push(temp);
            temp=temp->left;
        }
        temp=st.top();st.pop();
        res.push_back(temp->val);
        temp=temp->right;
    }
    return res;
}

vector<int> recursive_inorder(TreeNode*root){
    vector<int>res;
    auto dfs=[&](auto self,TreeNode*root)->void{
        if(!root)return;
        self(self,root->left);
        res.push_back(root->val);
        self(self,root->right);
    };
    dfs(dfs,root);
    return res;
}
vector<int> level_order(TreeNode*root){
    if(!root)return{};
    vector<int>res;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        res.push_back(temp->val);
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
    }
    return res;
}
void printTreeLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << "null ";
            }
        }
        cout << endl;
    }
}

int main(){
    vector<int>nums={1,2,3,4,5,6,-1,-1,-1,7,8,9,10,-1,-1,11,12};
    TreeNode*root=buildSampleTree(nums);
    vector<int>preorder=iterative_preorder(root);
    vector<int>inorder=iterative_inorder(root);
    vector<int>inorder2=recursive_inorder(root);
    vector<int>levelorder=level_order(root);
    // for(int val:inorder){
    //     cout<<val<<" ";
    // }
    // cout<<"\n"<<endl;
    // for(int val:levelorder){
    //     cout<<val<<" ";
    // }
    printTreeLevelOrder(root);
    return 0;
}

