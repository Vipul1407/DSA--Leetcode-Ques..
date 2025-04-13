class Solution {
public:
    //METHOD-3
    //BETTER.. 
    //TC= O(NLOGN)
    vector<int> twoSum(vector<int>& nums, int k) 
    {
        int n= nums.size();
        vector<int>ans;
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        int l=0,r=n-1;
        while(l<r)
        {
            int sum= vec[l].first+vec[r].first;
            if(sum==k)
            {
                ans.push_back(vec[l].second);
                ans.push_back(vec[r].second);
                break;
            }
            else if(sum<k)
            {
                l++;
            }
            else
            {
                r--;
            }
        }    
        return ans;
    }
};
/*
    //METHOD-1
    //BRUTE FORCE..
    //TC=O(N^2)
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

    //METHOD-2
    //OPTIMZED..
    //TC= O(N)
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
*/