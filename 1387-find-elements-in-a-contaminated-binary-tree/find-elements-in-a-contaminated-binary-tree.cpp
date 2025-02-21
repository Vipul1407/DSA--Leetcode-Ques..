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
class FindElements {
public:
    //METHOD-3
    //BFS..
    unordered_set<int>st;
    FindElements(TreeNode* root) 
    {
        queue<TreeNode*>q;
        root->val=0;
        q.push(root);

        while(!q.empty())
        {
            auto temp= q.front();
            st.insert(temp->val);
            q.pop();

            if(temp->left)
            {
                temp->left->val= temp->val*2+1; 
                q.push(temp->left);
            }
            if(temp->right)
            {
                temp->right->val= temp->val*2+2; 
                q.push(temp->right);
            }
        }
    }
    
    bool find(int target) 
    {
        return st.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
 /*
 // METHOD-1
// USING DFS..
// TC= O(N)+O(N)
TreeNode *root = NULL;
void dfs(TreeNode *root, int x)
{
    if (!root)
    {
        return;
    }
    root->val = x;
    dfs(root->left, 2 * x + 1);
    dfs(root->right, 2 * x + 2);
}
FindElements(TreeNode *root)
{
    this->root = root;
    dfs(root, 0);
}
bool search(TreeNode *root, int tar)
{
    if (!root)
    {
        return false;
    }
    if (root->val == tar)
    {
        return true;
    }
    return search(root->left, tar) || search(root->right, tar);
}
bool find(int tar)
{
    return search(root, tar);
}

// METHOD-2
// DFS+ UNORDERED SET
// TC= O(N)+O(1)
unordered_set<int> st;
void dfs(TreeNode *root, int x)
{
    if (!root)
    {
        return;
    }
    root->val = x;
    st.insert(root->val);
    dfs(root->left, 2 * x + 1);
    dfs(root->right, 2 * x + 2);
}
FindElements(TreeNode *root)
{
    dfs(root, 0);
}

bool find(int target)
{
    return st.find(target) != st.end();
}
 */