/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool solve(ListNode* head, TreeNode* root)
    {
        //list khtm hogyi means true return krna h
        if(!head)
        {
            return true;
        }
        //tree khtm hogya but list ni.. mtlb false return krna h
        if(!root)
        {
            return false;
        }
    
        if(root->val==head->val)
        {
            return solve(head->next,root->right) || solve(head->next,root->left);
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        if(!root)
        {
            return false;
        }
        return solve(head,root) || isSubPath(head,root->right) || isSubPath(head,root->left);
    }
};