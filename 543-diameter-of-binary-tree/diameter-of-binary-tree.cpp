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
    //METHOD-2
    //TC= O(N)
    int height(TreeNode* root, int &maxi) 
    {
        if(!root)
        {
            return 0;
        }
        int lht= height(root->left,maxi);
        int rht= height(root->right,maxi);
        maxi= max(maxi,lht+rht);
        return 1+ max(lht,rht);
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int maxi=0;
        height(root,maxi);
        return maxi;
    }
};
/*
    //METHOD-1
    //TC= O(N^2)
    int height(TreeNode* root) 
    {
        if(!root)
        {
            return 0;
        }
        int lht= height(root->left);
        int rht= height(root->right);
        return 1+ max(lht,rht);
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(!root)
        {
            return 0;
        }
        int lht= height(root->left);
        int rht= height(root->right);
        int maxi= lht+rht;
        int left= diameterOfBinaryTree(root->left);
        int right= diameterOfBinaryTree(root->right);
        return max(maxi,max(left,right));
    }
*/