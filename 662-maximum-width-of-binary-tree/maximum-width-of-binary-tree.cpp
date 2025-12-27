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
    //METHOD=1
    //DFS..
    void dfs(TreeNode* root, int level, long long idx, long long &ans, unordered_map<int,long long>&mp)
    {
        if(!root)
        {
            return;
        }
        //store the idx of 1st node at each level..
        if(!mp.count(level))
        {
            mp[level]= idx;
        }
        long long curr= idx-mp[level];
        ans= max(ans,curr+1);
        dfs(root->left,level+1,curr*2+1,ans,mp);
        dfs(root->right,level+1,curr*2+2,ans,mp);
    }
    int widthOfBinaryTree(TreeNode* root) 
    {
        unordered_map<int,long long>mp;
        long long ans=0;
        dfs(root,0,0,ans,mp);
        return (int)ans;
    }
};