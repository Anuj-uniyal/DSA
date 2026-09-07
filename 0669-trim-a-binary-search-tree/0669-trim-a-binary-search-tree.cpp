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
    TreeNode* trim(TreeNode* root,int l,int h){
        if(root==nullptr){
            return nullptr;
        }
        root->left=trim(root->left,l,h);
        root->right=trim(root->right,l,h);
        if(root->val>=l && root->val<=h){
            return root;
        }
        else{
            if(root->val<l){
                return root->right;
            }
            else{
                return root->left;
            }
        }
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return trim(root,low,high);
    }
};