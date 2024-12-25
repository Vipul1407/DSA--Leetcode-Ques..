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
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int>ans;
        if(!root)
        {
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(q.size())
        {
            int size= q.size();
            int maxi= INT_MIN;
            while(size--)
            {
                auto temp= q.front();
                maxi= max(maxi,temp->val);
                q.pop();
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};