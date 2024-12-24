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
    int solve(TreeNode* root, int &dia)
    {
        if(!root)
        {
            return 0;
        }
        int leftht= solve(root->left,dia);
        int rightht= solve(root->right,dia);
        dia= max(dia, leftht+rightht+1);
        return max(leftht,rightht)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int dia=0;
        solve(root,dia);
        return dia-1;//becoz we are counting edges    
    }
};