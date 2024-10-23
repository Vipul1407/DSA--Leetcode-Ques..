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

// Intuition ->> Sum of cousins= (Level Sum) - (Sibling sum)


// Approach 2 -> Traversing the tree only one time...
// Replacing each node value with siblingSum and calculating the level Order sum of next level in prev iteration

// TC= O(N)
// SC= O(N)

class Solution{
public: 
    TreeNode* replaceValueInTree(TreeNode* root) {
        // base case
        if(root== NULL)
        {
            return root;
        }  
        
        queue<TreeNode*> q;
        q.push(root);
        int levelSum= root->val;

        while(!q.empty())
        {
            int n= q.size();
            int nextLevelSum= 0;

            while(n--)
            {
                TreeNode* node= q.front();
                q.pop();
                
                // node->val= levelSum- siblingSum 
                node->val= levelSum- node->val;

                int siblingSum= 0;

             // NOTE WE CANNOT calc siblingSum and nextLevelSum at same time, first calc siblingSum then after calculate nextLevelSum
                if(node->left)
                {
                    siblingSum+= node->left->val;
                }

                if(node->right)
                {
                    siblingSum+= node->right->val;
                }

                if(node->left)
                {
                    nextLevelSum+= node->left->val;
                    node->left->val= siblingSum;
                    q.push(node->left);
                }

                if(node->right)
                {
                    nextLevelSum+= node->right->val;
                    node->right->val= siblingSum;
                    q.push(node->right);
                }
            }

            levelSum= nextLevelSum;
        }
       return root; 
    }
};








// Approach 1 ->>> 2 times traversing the tree, one for finding level order sum, other 
// for replacing each node value with levelSum- siblingSum    

// TC= O(2*N)
// SC= O(N)

/*

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        // base case
        if(root== NULL)
        {
            return root;
        } 

        // Step 1 ->> first build up the level order sum of each level in vector...
        vector<int> levelSum;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty())
        {
            int n= q.size();
            int sum= 0;
            while(n--)
            {
                TreeNode* node= q.front();
                q.pop();
               sum+= node->val;
               if(node->left){
                   q.push(node->left);
               }

               if(node->right){
                  q.push(node->right);
               }
            }
            
            // After completion of each level, insert level sum in vector..
            levelSum.push_back(sum);
        }


        // Step 2 ->> Replace each node value with levelSum - siblingSum
        int i= 1;
        q.push(root);
        root->val= 0;  // root has NO cousin

        while(!q.empty())
        {
            int m= q.size();
            while(m--)
            {
               int siblingSum= 0;
               TreeNode* node= q.front();
               q.pop();

               if(node->left){
                  siblingSum+= node->left->val;
               }

               if(node->right){
                  siblingSum+= node->right->val;
               }

               if(node->left){
                  node->left->val= levelSum[i]- siblingSum;
                  q.push(node->left);
               }

               if(node->right){
                  node->right->val= levelSum[i]- siblingSum;
                  q.push(node->right);
               }
            }
            
            // after completion of each level..
            i++;
        }

    return root;
    }
};

*/