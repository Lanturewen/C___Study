//
// Created by Lanture on 2022/11/2.
//
struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(){
        this->val=0;
        this->left= nullptr;
        this->right= nullptr;
    }
    TreeNode(int x): val(x),left(nullptr),right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right ): val(x), left(left), right(right){};
};