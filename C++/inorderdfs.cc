#include<iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;

    TreeNode(int v){
        val=v;
        left=nullptr;
        right=nullptr;
    }
};


void inorderTraversal(TreeNode *temp){
    if(temp==nullptr){
        return;
    }

    inorderTraversal(temp->left);
    cout<<temp->val;
    inorderTraversal(temp->right);
}

void preorderTraversal(TreeNode *temp){
    if(temp==nullptr){
        return;
    }

    cout<<temp->val;
    preorderTraversal(temp->left);
    preorderTraversal(temp->right);
}

void postorderTraversal(TreeNode *temp){
    if(temp==nullptr){
        return;
    }

    postorderTraversal(temp->left);
    postorderTraversal(temp->right);
    cout<<temp->val;
}

void postorderTrav(TreeNode *temp){
    if(temp==nullptr){
        return;
    }

    postorderTrav(temp->left);
    postorderTrav(temp->right);
}

int main(){

    TreeNode*root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

        //         1
        //     2       3
        // 4      5 6      7

    inorderTraversal(root);
    cout<<endl;
    preorderTraversal(root);
    cout<<endl;
    postorderTraversal(root);

}