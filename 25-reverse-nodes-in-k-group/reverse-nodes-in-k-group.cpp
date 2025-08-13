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
    int findlen(ListNode* head)
    {
        int cnt=0;
        while(head!=NULL)
        {
            head= head->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* solve(ListNode* head, int k, int len)
    {
        if(head==NULL || len<k)
        {
            return head;
        }

        //step1- reverse k nodes..
        ListNode* curr= head;
        ListNode* prev= NULL;
        ListNode* forward= NULL;
        int cnt=0;
        while(curr!=NULL && cnt<k)
        {
            forward= curr->next;
            curr->next= prev;
            prev= curr;
            curr= forward;
            cnt++;
        }

        //step2- recusion..
        if(forward!=NULL)
        {
            head->next= solve(forward,k,len-k);
        }
        return prev;//head of new reversed segment..
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        int len= findlen(head);
        return solve(head,k,len);
    }
};