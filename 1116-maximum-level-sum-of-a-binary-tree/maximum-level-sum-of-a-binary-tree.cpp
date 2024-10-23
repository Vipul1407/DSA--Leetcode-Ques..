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
    int maxLevelSum(TreeNode* root) 
    {
        // if(!root)
        // {
        //     return 0;
        // }
        queue<TreeNode*>q;
        q.push(root);
        int maxi= root->val;//can be initialized to INT_MIN
        int level=1;
        int ans=1;
        while(q.size())
        {
            int size= q.size();

            int sum=0;//initialized to 0 for each level
            
            //computation for a level
            for(int i=0;i<size;i++)
            {
                TreeNode* temp= q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            //want min level hence no equal sign
            if(sum>maxi)
            {
                maxi=sum;
                ans=level;
            }
            level++;//increment after updating
        }
        return ans;
    }
};