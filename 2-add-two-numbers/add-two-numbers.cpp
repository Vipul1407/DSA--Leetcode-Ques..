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
    ListNode* add(ListNode* first, ListNode* second)
    {
        int carry=0;
        ListNode* dummy= new ListNode(-1);
        ListNode* curr= dummy;
        while(first!=NULL || second!=NULL || carry!=0)
        {
            int x=0;
            if(first!=NULL)
            {
                x= first->val;
            }
            int y=0;
            if(second!=NULL)
            {
                y= second->val;
            }
            int sum= x+y+carry;
            ListNode* digit= new ListNode(sum%10);
            curr->next= digit;
            curr= curr->next;
            carry= sum/10;
            if(first!=NULL)
            {
                first= first->next;
            }
            if(second!=NULL)
            {
                second= second->next;
            }
        }
        ListNode* head= dummy->next;
        delete dummy;
        return head;
    }
    ListNode* addTwoNumbers(ListNode* first, ListNode* second) 
    {
        ListNode* ans= add(first,second); 
        return ans;
    }
};