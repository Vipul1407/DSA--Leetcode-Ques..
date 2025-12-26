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
    //METHOD-1
    //DFS..
    void dfs(TreeNode* root, int curr, int &ans)
    {
        if(!root)
        {
            return;
        }
        int temp= curr*10+root->val;
        if(!root->left && !root->right)
        {
            ans+= temp;
            return;
        }
        dfs(root->left,temp,ans);
        dfs(root->right,temp,ans);
    }
    int sumNumbers(TreeNode* root) 
    {
        if(!root)
        {
            return 0;
        }
        int ans=0;
        dfs(root,0,ans);
        return ans;
    }
};