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
    //  BFS..
    int sumNumbers(TreeNode* root) 
    {
        if(!root)
        {
            return 0;
        }
        int ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(q.size())
        {
            int n= q.size();
            while(n--)
            {
                int curr= q.front().second;
                auto top= q.front().first;
                q.pop();

                int temp= (curr*10)+top->val;
                if(!top->left && !top->right)
                {
                    ans+= temp;
                }
                if(top->left)
                {
                    q.push({top->left,temp});
                }
                if(top->right)
                {
                    q.push({top->right,temp});
                }
            }
        }
        return ans;
    }
};
/*
    //METHOD-1
    //DFS..
    void dfs(TreeNode* root, int curr, int &ans)
    {
        if(!root)
        {
            return;
        }
        int temp= curr*10+root->val;
        if(!root->left && !root->right)
        {
            ans+= temp;
            return;
        }
        dfs(root->left,temp,ans);
        dfs(root->right,temp,ans);
    }
    int sumNumbers(TreeNode* root) 
    {
        if(!root)
        {
            return 0;
        }
        int ans=0;
        dfs(root,0,ans);
        return ans;
    }
*/