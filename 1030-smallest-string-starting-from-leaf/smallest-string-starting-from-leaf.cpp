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
    void dfs(TreeNode* root, string curr, string &ans)
    {
        if(!root)
        {
            return;
        }
        string temp= char(root->val+'a')+curr;

        if(!root->left && !root->right)
        {
            if(ans=="" || temp<ans)
            {
                ans= temp;
            }
            return;
        }
        dfs(root->left,temp,ans);
        dfs(root->right,temp,ans);
    }
    string smallestFromLeaf(TreeNode* root) 
    {
        string ans;
        dfs(root,"",ans);
        return ans;
    }
};