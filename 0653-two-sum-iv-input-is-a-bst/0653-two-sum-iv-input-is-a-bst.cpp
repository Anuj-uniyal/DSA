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
    void inorder(TreeNode* root,vector<int>&v){
        if(root==nullptr)return;
        inorder(root->left,v);
        v.push_back(root->val);
         inorder(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        inorder(root,v);
        if(v.size()==1)return false;
        int m=0;int n=v.size()-1;
        while(m<n){
            if(v[m]+v[n]==k){
                return true;
            }
            else if(v[m]+v[n]<k){
                m++;
            }
            else{
                n--;
            }
        }
        return false;
    }
};