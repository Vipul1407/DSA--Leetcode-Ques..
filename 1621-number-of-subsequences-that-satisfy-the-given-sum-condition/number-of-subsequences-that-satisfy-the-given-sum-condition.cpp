class Solution {
public:
    #define MOD 1000000007
    int numSubseq(vector<int>& nums, int target) 
    {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=n-1;
        int ans=0;

        vector<int>power(n,0);
        power[0]=1;
        for(int i=1;i<n;i++)
        {   
            power[i]= (power[i-1]*2)%MOD;
        }

        while(l<=r)
        {
            if(nums[l]+nums[r]<=target)
            {
                int diff= r-l;
                ans= (ans+(power[diff]%MOD))%MOD;
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans%MOD;
    }
};