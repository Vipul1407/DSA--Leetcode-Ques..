class Solution {
public:
    int minSubarray(vector<int>& arr, int p) 
    {
        int n= arr.size();
        int sum=0;
        for(auto i:arr)
        {
            sum= (sum+i)%p;
        }
        int tar= sum%p;
        if(tar==0)
        {
            return 0;
        }
        unordered_map<int,int>mp;
        mp[0]=-1;
        int curr;
        int ans=n;//to find min length subarray

        // currsum - prevsum = tar
        // prevsum= currsum-tar
        //if we got this prevsum then we will update our min length..
        for(int i=0;i<n;i++)
        {
            curr= (curr+arr[i])%p;
            int remain= (curr-tar+p)%p;
            if(mp.find(remain)!=mp.end())
            {
                ans= min(ans,i-mp[remain]);
            }
            mp[curr]=i;
        }
        return ans==n? -1:ans;
    }
};