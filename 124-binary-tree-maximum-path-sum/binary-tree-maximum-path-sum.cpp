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
    //TC= O(N)
    int dfs(TreeNode* root, int &maxi)
    {
        if(!root)
        {
            return 0;
        }
        int lht= max(0,dfs(root->left,maxi));
        int rht= max(0,dfs(root->right,maxi));
        maxi= max(maxi,root->val+lht+rht);
        return root->val+ max(lht,rht);
    }
    int maxPathSum(TreeNode* root) 
    {
        if(!root)
        {
            return INT_MIN;
        }
        int maxi= INT_MIN;
        dfs(root,maxi);
        return maxi;
    }
};