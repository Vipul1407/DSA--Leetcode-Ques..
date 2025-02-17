class Solution {
public:
    int maximumSum(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        int ans=-1;
        for(auto i:nums)
        {
            int temp=i;
            int sum=0;
            while(temp)
            {
                sum+= temp%10;
                temp/=10;
            }
            if(mp.find(sum)!=mp.end())
            {
                ans= max(ans,mp[sum]+i);
                mp[sum]= max(mp[sum],i);
            }
            else
            {
                mp[sum]= i;
            }
        }  
        return ans;
    }
};