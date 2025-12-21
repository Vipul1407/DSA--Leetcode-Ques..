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
    //METHOD-2..
    int dfs(TreeNode* root, int maxi)
    {
        if(!root)
        {
            return 0;
        }
        if(root->val>= maxi)
        {
            maxi= max(maxi,root->val);
            return 1+ dfs(root->left,maxi)+ dfs(root->right,maxi);
        }
        maxi= max(maxi,root->val);
        return dfs(root->left,maxi)+dfs(root->right,maxi);
    }
    int goodNodes(TreeNode* root) 
    {
       return dfs(root,root->val);
    }
};
/*
    //METHOD-1..
    void dfs(TreeNode* root, int maxi, int &cnt)
    {
        if(!root)
        {
            return;
        }
        if(root->val>= maxi)
        {
            cnt++;
        }
        maxi= max(maxi,root->val);
        dfs(root->left,maxi,cnt);
        dfs(root->right,maxi,cnt);
    }
    int goodNodes(TreeNode* root) 
    {
       int cnt=0;
       dfs(root,root->val,cnt);
       return cnt;
    }
*/