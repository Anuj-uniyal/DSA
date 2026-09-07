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
void inorder(TreeNode* root,vector<TreeNode*>&v){
    if(root==nullptr){
        return;
    }
    inorder(root->left,v);
    v.push_back(root);
    inorder(root->right,v);
}
void recoverTree(TreeNode* root) {
        vector<TreeNode*>v;
        inorder(root,v);
        TreeNode* prev=v[0];
        TreeNode* curr=v[1];
        int x=0;
        TreeNode* first=nullptr;
        TreeNode* second=nullptr;
        for(int i=0;i<v.size()-1;++i){
            if(curr->val<prev->val){
                x++;
                if(x==1){
                    first=prev;
                    second=curr;
                }
                else{
                    second=curr;
                }
                
            }
                prev=curr;
                curr=v[i+2];
        }

        swap(first->val,second->val);
        return;
    }
};