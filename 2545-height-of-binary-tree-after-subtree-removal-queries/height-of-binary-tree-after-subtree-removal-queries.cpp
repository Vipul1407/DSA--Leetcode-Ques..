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
    int level[100001];//level of each node
    int height[100001];//height of each node
    pair<int,int>maxht[100001];//to store 2 max ht. at each level 

    int fun(TreeNode* root, int lev)
    {
        if(!root)
        {
            return 0;
        }
        level[root->val]= lev;
        height[root->val]= 1+max(fun(root->left,lev+1),fun(root->right,lev+1));
        if(height[root->val]>maxht[lev].first)
        {
            maxht[lev].second= maxht[lev].first;
            maxht[lev].first= height[root->val];
        }
        else if(height[root->val]>maxht[lev].second)
        {
            maxht[lev].second= height[root->val];
        }
        return height[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& quer) 
    {
        vector<int>ans;
        fun(root,0);//initial level=0
        for(auto i:quer)
        {
            int L= level[i];//upper height from node at same level...
            int H= maxht[L].first;//lower height from node at same level...
            if(height[i]==maxht[L].first)
            {
                H= maxht[L].second;
            }
            ans.push_back(L+H-1);
        }
        return ans;
    }
};

/*
// TLE
// METHOD-1
// TC=O(N^2)
int height(TreeNode *root, int x)
{
    if (!root)
    {
        return 0;
    }
    if (root->val == x)
    {
        return 0;
    }
    return 1 + max(height(root->left, x), height(root->right, x));
}
vector<int> treeQueries(TreeNode *root, vector<int> &quer)
{
    vector<int> ans;
    for (auto i : quer)
    {
        ans.push_back(height(root, i) - 1);
    }
    return ans;
}
*/