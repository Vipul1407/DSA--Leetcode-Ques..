class Solution {
public:
    int reductionOperations(vector<int>& nums) 
    {
        //max heap..
        priority_queue<int>pq(nums.begin(),nums.end());

        int top1;
        int top2;
        int prefixcnt=0;
        int ans=0;
        while(pq.size()>=2)
        {
            top1= pq.top();
            prefixcnt++;
            pq.pop();
            while(pq.size() && pq.top()==top1)
            {
                pq.pop();
                prefixcnt++;
            }
            top2= pq.top();
            //we will not pop top2 element..
            if(pq.size())
            {
                ans+= prefixcnt;
            }
        }
        return ans;
    }
};