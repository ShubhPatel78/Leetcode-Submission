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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mpp;
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* temp=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            mpp[col][row].insert(temp->val);
            if(temp->right!=NULL){
                q.push({temp->right,{row+1,col+1}});
            }
            if(temp->left!=NULL){
                q.push({temp->left,{row+1,col-1}});
            }
        }
        for(auto p:mpp){
            vector<int>a;
            for(auto q: p.second){
                a.insert(a.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(a);
        }
        return ans;
    }
};