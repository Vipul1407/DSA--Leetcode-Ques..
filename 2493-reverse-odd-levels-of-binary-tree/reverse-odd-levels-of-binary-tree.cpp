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
    //METHOD-1
    //BFS..
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        if(!root)
        {
            return root;
        }
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(q.size())
        {
            int n= q.size();
            //vec is storing address of nodes...
            vector<TreeNode*>vec;
            while(n--)
            {
                TreeNode* top= q.front();
                vec.push_back(top);
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
            if(level%2==1)
            {
                int i=0;
                int j= vec.size()-1;
                while(i<=j)
                {
                    //we are swapping the address values..
                    swap(vec[i]->val,vec[j]->val);
                    i++;
                    j--;
                }
            }
            level++;
        }
        return root;
    }
};