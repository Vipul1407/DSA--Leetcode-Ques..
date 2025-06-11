class Solution {
public:
    //METHOD-1
    //Binary Search..
    //TC= O(NLOGN)
    long long calculate(vector<int>& nums, vector<int>& cost, long long mid)
    {
        long long ans=0;
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            ans+= abs(nums[i]-mid)*cost[i];
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) 
    {
        long long l=1;
        long long r= *max_element(nums.begin(),nums.end());
        long long ans= INT_MAX;
        while(l<=r)
        {
            long long mid= l+(r-l)/2;
            long long cc1= calculate(nums,cost,mid);
            long long cc2= calculate(nums,cost,mid+1);
            ans= min(cc2,cc1);
            if(cc1<cc2)
            {
                r= mid-1;
            }
            else
            {
                l= mid+1;
            }
        }
        return ans==INT_MAX ? 0:ans;
    }
};