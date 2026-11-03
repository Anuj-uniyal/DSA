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
pair<int,int>findDiameter(TreeNode* root){
    if(root==nullptr)return {0,0};
   pair<int,int>l=findDiameter(root->left);
   pair<int,int>r=findDiameter(root->right);
   return {max({l.first,r.first,(l.second+r.second+1)}), max(l.second,r.second)+1};
}
    int diameterOfBinaryTree(TreeNode* root) {
        return findDiameter(root).first-1;
    }
};