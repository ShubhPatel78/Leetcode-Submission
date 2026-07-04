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
    void getparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& mpp){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left!=NULL){
                mpp[node->left]=node;
                q.push(node->left);
            }
            if(node->right!=NULL){
                mpp[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mpp;
        getparent(root,mpp);
        vector<int>ans;
        unordered_map<TreeNode*,int>vis;
        queue<pair<TreeNode*,int>>q;
        vis[target]++;
        q.push({target,0});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int dis=q.front().second;
            q.pop();
            if(dis==k){
                ans.push_back(node->val);
            }
            if(node->left!=NULL && vis.find(node->left)==vis.end()){
                q.push({node->left,dis+1});
                vis[node->left]++;
            }
            if(node->right!=NULL && vis.find(node->right)==vis.end()){
                q.push({node->right,dis+1});
                vis[node->right]++;
            }
            TreeNode* parent=mpp[node];
            if(parent!=NULL && vis.find(parent)==vis.end()){
                q.push({parent,dis+1});
                vis[parent]++;
            }
        }
        return ans;
    }
};