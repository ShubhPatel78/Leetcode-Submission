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
    TreeNode* f(vector<int>&inorder,int is,int ie,vector<int>&preorder,int ps,int pe,map<int,int>&mpp){
        if(is>ie || ps>pe){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[ps]);
        int inroot=mpp[root->val];
        int left=inroot-is;
        root->left=f(inorder,is,inroot-1,preorder,ps+1,ps+left,mpp);
        root->right=f(inorder,inroot+1,ie,preorder,ps+left+1,pe,mpp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder=preorder;
        sort(inorder.begin(),inorder.end());
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return f(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,mpp);
    }
};