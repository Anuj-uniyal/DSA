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
    int minDepth2(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        if(root->left==nullptr){
            return 1+minDepth2(root->right);
        }
        if(root->right==nullptr){
            return 1+minDepth2(root->left);
        }
        return 1+min(minDepth2(root->left),minDepth2(root->right));
    }
    int minDepth(TreeNode* root) {
        return minDepth2(root);
    }
};