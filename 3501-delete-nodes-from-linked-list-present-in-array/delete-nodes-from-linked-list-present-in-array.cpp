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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        unordered_set<int>st;
        for(auto i:nums)
        {
            st.insert(i);
        }
        ListNode* dummy= new ListNode(-1);
        ListNode* curr= dummy;
        ListNode* temp= head;
        while(temp)
        {
            if(st.find(temp->val)!=st.end())
            {
                curr->next= temp->next;
            }
            else
            {
                curr->next= temp;
                curr=curr->next;
            }
            temp=temp->next;
        }
        curr->next= NULL;
        head=dummy->next;
        delete dummy;
        return head;
    }
};