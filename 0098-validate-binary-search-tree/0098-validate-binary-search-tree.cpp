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
    void inorder(TreeNode* curr,TreeNode* &prev,bool &isBst){
        if(curr==nullptr){
            return;
        }
        inorder(curr->left,prev,isBst);
        if(prev!=nullptr && curr->val<=prev->val){
            isBst=false;
        }
        prev=curr;
        inorder(curr->right,prev,isBst);
    }
    bool isValidBST(TreeNode* root) {
        bool a=true;
        TreeNode* prev=nullptr;
        inorder(root,prev,a);
        if(a){
            return true;
        }
        else{
            return false;
        }
    }
};