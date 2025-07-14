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
class Solution {
public:
    int getDecimalValue(ListNode* head) 
    {
        string ans;
        while(head!=NULL)
        {
            ans+= (head->val+'0');
            head= head->next;
        }

        int finalans=0;
        int n= ans.size();
        for(int i=0;i<n;i++)
        {
            finalans+= (1<<i)* (ans[n-i-1]-'0');
        }
        return finalans;
    }
};