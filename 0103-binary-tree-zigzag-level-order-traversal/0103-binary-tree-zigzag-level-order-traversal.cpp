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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        queue<TreeNode*>q;
        if(root==nullptr){
            return result;
        }
        q.push(root);
        bool leftToRight=true;
        
        while(q.size()!=0){
            int n=q.size();
            vector<int>v(n);
            for(int i=0;i<n;++i){
                TreeNode* temp=q.front();
                q.pop();
                int idx;
                if(leftToRight){
                    idx=i;
                }
                else{
                    idx=n-i-1;
                }
                v[idx]=temp->val;
                if(temp->left!=nullptr){
                q.push(temp->left);
               }
                if(temp->right!=nullptr){
                q.push(temp->right);
               }
            }
            result.push_back(v);
            leftToRight=!leftToRight;
            v.clear();
            
        }
        return result;
    }
};