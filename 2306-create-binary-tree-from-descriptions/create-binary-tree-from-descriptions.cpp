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

    TreeNode* createBinaryTree(vector<vector<int>>& des) 
    {
        unordered_map<int,TreeNode*>mp;
        unordered_map<int,bool>hasparent;
        for(auto i:des)
        {
            int p= i[0];
            int c= i[1];
            bool left= i[2];
            TreeNode* parent= NULL;
            TreeNode* child= NULL;

            if(mp.find(p)==mp.end())
            {
                parent= new TreeNode(p);
            }
            else
            {
                parent= mp[p];
            }
            if(mp.find(c)==mp.end())
            {
                child= new TreeNode(c);
            }
            else
            {
                child= mp[c];
            }
            if(left)
            {
                parent->left= child;
            }
            else
            {
                parent->right= child;
            }
            mp[p]= parent;
            mp[c]= child;
            hasparent[c]=true;
        }

        TreeNode* root= NULL;
        for(auto i:mp)
        {
            if(!hasparent[i.first])
            {
                root= i.second;
                break;
            }
        }
        return root;
    }
};