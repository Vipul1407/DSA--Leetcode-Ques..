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
    // METHOD-2
    // OPTIMIZED APPROACH
    TreeNode* solve(int prestart,int poststart,int preend,vector<int>& preorder,vector<int>& postorder,unordered_map<int,int>&mp)
    {
        if(prestart>preend)
        {
            return NULL;
        }
        TreeNode* root= new TreeNode(preorder[prestart]);
        if(prestart==preend)
        {
            return root;
        }
        int nextnode= preorder[prestart+1];
        int j= mp[nextnode];
        int num= j-poststart+1;
        root->left= solve(prestart+1,poststart,prestart+num,preorder,postorder,mp);
        root->right= solve(prestart+num+1,j+1,preend,preorder,postorder,mp);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
    {
        int n= postorder.size();
        //storing elements and index of postorder..
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[postorder[i]]=i;
        }
        return solve(0,0,n-1,preorder,postorder,mp);
    }
};