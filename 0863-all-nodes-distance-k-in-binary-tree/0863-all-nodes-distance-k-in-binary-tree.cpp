/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void bfs(TreeNode* target,int k,vector<int>&v,unordered_map<TreeNode*,TreeNode*>&um){
     queue<TreeNode*>q;
     q.push(target);
     unordered_set<int>s;//ye already visited ka dhyaan rkhega
     s.insert(target->val);
     int currLevel=0;
     while(q.size()>0){
        int n=q.size();
        if(currLevel==k){
            break;
        }
        for(int i=0;i<n;++i){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left && !s.count(temp->left->val)){
                q.push(temp->left);
                s.insert(temp->left->val);
            }
            if(temp->right && !s.count(temp->right->val)){
                q.push(temp->right);
                s.insert(temp->right->val);
            }
            if(um.count(temp) && !s.count(um[temp]->val)){
                q.push(um[temp]);
                s.insert(um[temp]->val);
            }
        }
        currLevel++;
     }
     int x=q.size();
     while(x--){
        v.push_back(q.front()->val);
        q.pop();
     }
     return ;
    }
    void fillMap(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&um){
        if(root==nullptr){
            return;
        }
        if(root->left!=nullptr){
            um[root->left]=root;
        }
        if(root->right!=nullptr){
            um[root->right]=root;
        }
        fillMap(root->left,um);
        fillMap(root->right,um);
        return;

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>um;
         fillMap(root,um);
         vector<int>v;
         bfs(target,k,v,um);
         return v;
    }
};