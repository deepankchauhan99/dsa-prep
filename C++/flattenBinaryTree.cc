#include<iostream>
#include<vector>
#include<stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createTree(){

}

void flatten(TreeNode* root){
    TreeNode* temp=root;
    while(temp){
        if(temp->left){
            TreeNode*tempRight=temp->right;
            // temp->right=temp->left;
            TreeNode*temp1=temp->left;
            TreeNode*tempLeft=temp->left;
            while(tempLeft->right){
                tempLeft=tempLeft->right;
            }
            temp->right=temp1;
            temp->left=nullptr;
            tempLeft->right=tempRight;
        }
        temp=temp->right;
    }
}

int main(){

}