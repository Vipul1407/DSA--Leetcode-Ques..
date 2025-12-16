/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&mp)
    {
        if(!root)
        {
            return;
        }
        if(root->right)
        {
            mp[root->right]= root;
            solve(root->right,mp);
        }
        if(root->left)
        {
            mp[root->left]= root;
            solve(root->left,mp);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        if(!root)
        {
            return {};
        }
        if(k==0)
        {
            return {target->val};
        }
        unordered_map<TreeNode*,TreeNode*>mp;
        solve(root,mp);
        vector<int>ans;
        queue<TreeNode*>q;
        unordered_set<TreeNode*>st;
        q.push(target);
        st.insert(target);
        while(q.size() && k>0)
        {
            int n= q.size();
            while(n--)
            {
                auto top= q.front();
                q.pop();
    
                if(top->left && !st.count(top->left))
                {
                    q.push(top->left);
                    st.insert(top->left);
                }
                if(top->right && !st.count(top->right))
                {
                    q.push(top->right);
                    st.insert(top->right);
                }
                if(mp[top] && !st.count(mp[top]))
                {
                    q.push(mp[top]);
                    st.insert(mp[top]);
                }
            }
            k--;
        }
        while(q.size())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};