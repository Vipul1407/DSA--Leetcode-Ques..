class Solution {
public:
    //METHOD-2
    //BETTER..
    vector<int> twoSum(vector<int>& nums, int k) 
    {
        int n= nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(k-nums[i])!=mp.end())
            {
                ans.push_back(i);
                ans.push_back(mp[k-nums[i]]);
            }
            mp[nums[i]]=i;
        }    
        return ans;
    }
};
/*
//METHOD-1
    //BRUTE FORCE..
    vector<int> twoSum(vector<int>& nums, int k) 
    {
        int n= nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==k)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }    
        return ans;
    }
*/