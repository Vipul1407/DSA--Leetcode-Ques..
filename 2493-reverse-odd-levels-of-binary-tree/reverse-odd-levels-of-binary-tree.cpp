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
    TreeNode* dfs(TreeNode* ll, TreeNode* rr, int level)
    {
        if(!ll || !rr)
        {
            return NULL;
        }
        if(level%2!=0)
        {
           swap(ll->val,rr->val);
        }
        dfs(ll->left,rr->right,level+1);
        dfs(ll->right,rr->left,level+1);
        return NULL;
    }
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        dfs(root->left,root->right,1);  
        return root;
    }
};