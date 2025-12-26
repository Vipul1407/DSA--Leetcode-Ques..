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
    bool dfs(TreeNode* L, TreeNode* R) 
    {
        if(!L && !R)
        {
            return true;
        }
        if(!L && R)
        {
            return false;
        }
        if(!R && L)
        {
            return false;
        }
        if(L->val!=R->val)
        {
            return false;
        }
        return dfs(L->left,R->right) && dfs(L->right,R->left);
    }
    bool isSymmetric(TreeNode* root) 
    {
        return dfs(root->left,root->right);
    }
};