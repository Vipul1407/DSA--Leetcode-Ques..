class Solution {
public:
    //METHOD-2
    //OPTIMIZED..
    int subarraySum(vector<int>& nums, int k) 
    {
        int ans=0, prefix=0;
        int n= nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            prefix+= nums[i];
            ans+= mp[prefix-k];
            mp[prefix]++;
        }
        return ans;
    }
};
/*
    //METHOD-1
    //BRUTE FORCE..
    int subarraySum(vector<int>& nums, int k) 
    {
        int ans=0;
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+= nums[j];
                if(sum==k)
                {
                    ans++;
                    //we will not break as our nums may contains negative values
                    //break;
                }
            }
        }
        return ans;
    }
*/