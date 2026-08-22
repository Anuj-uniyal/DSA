/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void right(TreeNode* root,int lvl,vector<int>&v){
        if(root==nullptr){
            return;
        }
        if(lvl==v.size()){
            v.push_back(root->val);
        }
        right(root->right,lvl+1,v);
        right(root->left,lvl+1,v);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        right(root,0,v);
        return v;
    }
};