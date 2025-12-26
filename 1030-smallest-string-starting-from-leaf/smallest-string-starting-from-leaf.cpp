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
    string smallestFromLeaf(TreeNode* root) 
    {
        if(!root)
        {
            return "";
        }
        string ans;
        queue<pair<TreeNode*,string>>q;
       
        q.push({root,""});

        while(q.size())
        {
            int n= q.size();
            while(n--)
            {
                auto top= q.front().first;
                auto curr= q.front().second;
                q.pop();


                string temp= char(top->val+'a')+curr;
                if(!top->left && !top->right)
                {
                    if(ans=="" || temp<ans)
                    {
                        ans= temp;
                    }
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
    void dfs(TreeNode* root, string curr, string &ans)
    {
        if(!root)
        {
            return;
        }
        string temp= char(root->val+'a')+curr;

        if(!root->left && !root->right)
        {
            if(ans=="" || temp<ans)
            {
                ans= temp;
            }
            return;
        }
        dfs(root->left,temp,ans);
        dfs(root->right,temp,ans);
    }
    string smallestFromLeaf(TreeNode* root) 
    {
        string ans;
        dfs(root,"",ans);
        return ans;
    }
*/