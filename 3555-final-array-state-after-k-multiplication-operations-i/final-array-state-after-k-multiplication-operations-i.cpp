class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) 
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
        }
        while(k--)
        {
            int ele= pq.top().first*mul;
            int idx= pq.top().second;
            pq.pop();
            pq.push({ele,idx});
        }
        vector<int>ans(n,0);
        while(pq.size())
        {
            ans[pq.top().second]= pq.top().first;
            pq.pop();
        }
        return ans;
    }
};