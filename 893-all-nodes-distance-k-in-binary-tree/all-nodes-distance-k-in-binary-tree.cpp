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
    void inorder(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&mp)
    {
        if(!root)
        {
            return;
        }
        if(root->left)
        {
            mp[root->left]= root;
            inorder(root->left,mp);
        }
        if(root->right)
        {
            mp[root->right]= root;
            inorder(root->right,mp);
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
        inorder(root,mp);
        unordered_set<int>st;
        queue<TreeNode*>q;
        q.push(target);
        st.insert(target->val);

        while(!q.empty() && k>0)
        {
            int n= q.size();
            while(n--)
            {
                auto top= q.front();
                if(top->left and st.find(top->left->val)==st.end())
                {
                    q.push(top->left);
                    st.insert(top->left->val);
                }
                if(top->right and st.find(top->right->val)==st.end())
                {
                    q.push(top->right);
                    st.insert(top->right->val);
                }
                if(mp[top] && st.find(mp[top]->val)==st.end())
                {
                    st.insert(mp[top]->val);
                    q.push(mp[top]);
                }
                q.pop();
            }
            k--;
        }
        vector<int>ans;
        while(q.size())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};