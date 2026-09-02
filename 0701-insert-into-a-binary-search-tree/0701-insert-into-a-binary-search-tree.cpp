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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr=root;
        TreeNode* par=nullptr;
        if(root==nullptr){
            TreeNode* p=new TreeNode(val);
            return p;
        }
        while(curr!=nullptr){
          if(val<=curr->val ){
            par=curr;
            curr=curr->left;
         }
         else if(val>curr->val){
            par=curr;
            curr=curr->right;
         }
        }
        TreeNode* x=new TreeNode(val);
        if(val>par->val){
             par->right=x;
        }
        else{
            par->left=x;
        }
        
        return root;
    }
};