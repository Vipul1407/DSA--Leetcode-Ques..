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
    //BFS..
    int maxDepth(TreeNode* root) 
    {
        if(!root)
        {
            return 0;
        }
        queue<TreeNode*>q;
        int depth=0;
        q.push(root);
        while(q.size())
        {
            int n= q.size();
            depth++;
            while(n--)
            {
                auto top= q.front();
                q.pop();
                if(top->left)
                {
                    q.push(top->left);
                }
                if(top->right)
                {
                    q.push(top->right);
                }
            }
        }
        return depth;
    }
};
/*
    //METHOD-1
    //DFS..
    int maxDepth(TreeNode* root) 
    {
        if(!root)
        {
            return 0;
        }
        int leftd= maxDepth(root->left);
        int rightd= maxDepth(root->right);
        return 1+max(leftd,rightd);
    }
*/