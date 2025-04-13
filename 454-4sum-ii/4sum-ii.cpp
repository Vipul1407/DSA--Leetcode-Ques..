class Solution {
public:
    //METHOD-3
    //OPTIMIZED..
    //TC= O(N^2)
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        int n= nums1.size();
        int cnt=0;
        unordered_map<long long,int>mp;

        for(auto a:nums1)
        {
            for(auto b:nums2)
            {
                long long sum=a;
                sum+=b;
                mp[sum]++;
            }
        }
        for(auto c:nums3)
        {
            for(auto d:nums4)
            {
                long long sum= c;
                sum+= d;
                if(mp.find(-sum)!=mp.end())
                {
                    cnt+= mp[-sum];
                }
            }
        }
        return cnt;
    }
};
/*
    //METHOD-1
    //BRUTE FORCE..
    //TC= O(N^4)

    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        int n= nums1.size();
        int cnt=0;
        for(auto a:nums1)
        {
            for(auto b:nums2)
            {
                for(auto c:nums3)
                {
                    for(auto d:nums4)
                    {
                        if(a+b+c+d==0)
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }

    //METHOD-2
    //BETTER FORCE..
    //TC= O(N^3)
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        int n= nums1.size();
        int cnt=0;
        unordered_map<int,int>mp;
        for(auto d:nums4)
        {
            mp[d]++;
        }
        for(auto a:nums1)
        {
            for(auto b:nums2)
            {
                for(auto c:nums3)
                {
                    long long sum= a;
                    sum+= b;
                    sum+= c;
                    if(mp.find(-sum)!=mp.end())
                    {
                        cnt+= mp[-sum];
                    }
                }
            }
        }
        return cnt;
    }
*/