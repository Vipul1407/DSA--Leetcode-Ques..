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
    long long getsum(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        return root->val+ getsum(root->left)+ getsum(root->right);
    }
    int solve(TreeNode* root, long long &total, long long &ans)
    {
        if(!root)
        {
            return 0;
        }
        int leftsum= solve(root->left,total,ans);
        int rightsum= solve(root->right,total,ans);
        long long subtreesum= root->val+ leftsum+ rightsum;
        ans= max(ans, subtreesum*(total-subtreesum));
        return subtreesum;
    }
    int maxProduct(TreeNode* root) 
    {
        if(!root)
        {
            return 0;
        }
        const int mod= 1000000007;
        long long total= getsum(root);
        long long ans=0;
        solve(root,total,ans);
        return ans%mod;
    }
};