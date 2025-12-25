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
    //TC= O(N^2)
    int height(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        int lht= height(root->left);
        int rht= height(root->right);
        return 1+max(lht,rht);
    }
    bool isBalanced(TreeNode* root) 
    {
        if(!root)
        {
            return true;
        }
        int lefth= height(root->left);
        int righth= height(root->right);
        if(abs(lefth-righth)>1)
        {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};