class Solution {
public:
    #define ll long long
    vector<long long> minOperations(vector<int>& nums, vector<int>& quer) 
    {
        int n= nums.size();
        int m= quer.size();
        sort(nums.begin(),nums.end());

        vector<ll>prefix(n+1,0);
        for(int i=0;i<n;i++)
        {  
            prefix[i+1]= prefix[i]+nums[i];
        }
        vector<ll>ans;
        for(auto &q:quer)
        {
            auto ub= upper_bound(nums.begin(),nums.end(),q)-nums.begin();
            ll inc= q*ub- prefix[ub];
            ll dec= prefix[n]-prefix[ub] - (n-ub)*q;
            ans.push_back(inc+dec);
        }
        return ans;
    }
};