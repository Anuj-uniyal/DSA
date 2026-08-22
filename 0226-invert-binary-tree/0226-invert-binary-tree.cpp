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
TreeNode* reverse(TreeNode* root){
     if(root==nullptr){
        return nullptr;
     }
     swap(root->left,root->right);
     reverse(root->left);
     reverse(root->right);
     return root;
}
    TreeNode* invertTree(TreeNode* root) {
        return reverse(root);
    }
};