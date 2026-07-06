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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<double>a;
        while(!q.empty()){
            int size=q.size();
            double sum=0;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                sum=sum+(node->val);
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            a.push_back(sum);
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        if(k>a.size()){
            return -1;
        }
        long long ans=a[k-1];
        return ans;
    }
};