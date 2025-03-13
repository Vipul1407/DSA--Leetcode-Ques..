class Solution {
public:
    // METHOD-2
    // BINARY SEARCH OPTIMIZED..
    bool isvalid(int k,vector<int>& nums, vector<vector<int>>& quer)
    {
        int n= nums.size();
        vector<int>pref(n,0);
        for(int i=0;i<=k;i++)
        {
            int s= quer[i][0];
            int e= quer[i][1];
            int x= quer[i][2];
            pref[s]+=x;
            if(e+1<n)
            {
                pref[e+1]-=x;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+= pref[i];
            if(nums[i]-sum>0)
            {
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& quer) 
    {
        int Q= quer.size();
        int n= nums.size();
        int cnt=0;
        for(auto i:nums)
        {
            if(i==0)
            {
                cnt++;
                if(cnt==n)
                {
                    return 0;
                }
            }
            else
            {
                break;
            }
        }
        int l=0;
        int r= Q-1;
        int ans= -1;
        while(l<=r)
        {
            int mid= (l+r)/2;
            if(isvalid(mid,nums,quer))
            {
                ans= mid+1;
                r= mid-1;
            }
            else
            {
                l= mid+1;
            }
        }
        return ans;
    }
};
/*
// METHOD-1
// BRUTE FORCE..
// TLE..
// TC= O(Quer*(Quer+N))
    bool isvalid(int k,vector<int>& nums, vector<vector<int>>& quer)
    {
        int n= nums.size();
        vector<int>pref(n,0);
        for(int i=0;i<=k;i++)
        {
            int s= quer[i][0];
            int e= quer[i][1];
            int x= quer[i][2];
            pref[s]+=x;
            if(e+1<n)
            {
                pref[e+1]-=x;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+= pref[i];
            if(nums[i]-sum>0)
            {
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& quer) 
    {
        int Q= quer.size();
        int n= nums.size();
        int cnt=0;
        for(auto i:nums)
        {
            if(i==0)
            {
                cnt++;
                if(cnt==n)
                {
                    return 0;
                }
            }
            else
            {
                break;
            }
        }
        for(int k=0;k<Q;k++)
        {
            if(isvalid(k,nums,quer))
            {
                return k+1;
            }
        }
        return -1;
    }
*/