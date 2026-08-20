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
bool find(TreeNode* p, TreeNode* q){
    if(p==nullptr && q==nullptr){
        return true;
    }
    if(p==nullptr && q!=nullptr){
        return false;
    }
    if(p!=nullptr && q==nullptr){
        return false;
    }
     bool f1=find(p->left,q->left);
     bool f2=find(p->right,q->right);
     bool f3=p->val==q->val;
     return f1&&f2&&f3;

}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return find(p,q);
    }
};