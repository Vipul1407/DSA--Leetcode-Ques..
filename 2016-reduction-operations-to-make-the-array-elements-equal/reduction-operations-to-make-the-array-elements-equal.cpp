class Solution {
public:
    //METHOD-2
    //SORTING..
    //TC= O(NLOGN)
    int reductionOperations(vector<int>& nums) 
    {
        int n= nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());

        for(int i=n-1;i>=1;i--)
        {
           if(nums[i]==nums[i-1])
            {
                continue;
            }
            ans+= n-i;
        }
        return ans;
    }
};
/*
    
//METHOD-1
//MAX HEAP..
//TC= O(NLOGN)
int reductionOperations(vector<int> &nums)
{
    // max heap..
    priority_queue<int> pq(nums.begin(), nums.end());

    int top1;
    int top2;
    int prefixcnt = 0;
    int ans = 0;
    while (pq.size() >= 2)
    {
        top1 = pq.top();
        prefixcnt++;
        pq.pop();
        while (pq.size() && pq.top() == top1)
        {
            pq.pop();
            prefixcnt++;
        }
        top2 = pq.top();
        // we will not pop top2 element..
        // but if we have nothing in our pq, means all lements equal now in that case we don't need to add anything in ans..
        //for eg. [1,1,1] here ans must be 0
        if (pq.size())
        {
            ans += prefixcnt;
        }
    }
    return ans;
}

*/