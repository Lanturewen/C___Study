//
// Created by Lanture on 2022/12/1.
#include<vector>
#include<queue>
//#include
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int> > res;
        queue<TreeNode*> q;
        q.push(root);
        int idx = 0;
        while(!q.empty()){
            deque<int> dq;
            int size = q.size();
            idx++;
            while(size-->0){
                TreeNode* node = q.front();
                q.pop();
                if(idx%2==1){
                    dq.push_back(node->val);
                }else{
                    dq.push_front(node->val);
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            // res.push_back(dq);
            res.push_back(vector<int>(dq.begin(),dq.end())); //看deque怎么转化为vector? ->iterator.
        }
        return res;
    }
};