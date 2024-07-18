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
    
    int ans=0;
    vector<int> dfs(TreeNode* root, int d)
    {
        if(!root)
        {
            return {};
        }
        if(!root->left && !root->right)
        {
            return {1};
        }
        vector<int>l= dfs(root->left,d);
        vector<int>r= dfs(root->right,d);
        vector<int>vec;

        for(auto &a:l)
        {
            for(auto &b:r)
            {
                if(a+b<=d)
                {
                    ans++;
                }
            }
            a++;
            if(a<d)
            {
                vec.push_back(a);
            }
        }
        for(auto &b:r)
        {
            b++;
            if(b<d)
            {
                vec.push_back(b);
            }
        }
        return vec;
    }
    int countPairs(TreeNode* root, int d) 
    {
        dfs(root,d);
        return ans;
    }
};