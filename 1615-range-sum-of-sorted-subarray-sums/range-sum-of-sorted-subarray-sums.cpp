class Solution {
public:
    #define MOD 1000000007
    int rangeSum(vector<int>& nums, int n, int left, int right) 
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
        }
        int ans=0;
        for(int i=1;i<=right;i++)
        {
            int sum= pq.top().first;
            int idx= pq.top().second;
            pq.pop();
            if(idx+1<n)
            {
                int newsum= (sum+nums[idx+1])%MOD;
                pq.push({newsum,idx+1});
            }
            if(i>=left)
            {
                ans= (ans+sum)%MOD;
            }
        }
        return ans;
    }
};