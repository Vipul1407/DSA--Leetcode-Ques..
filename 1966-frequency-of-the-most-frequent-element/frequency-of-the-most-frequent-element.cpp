class Solution {
public:
    //METHOD-1
    //BINARY SEARCH..
    int binary(int i, vector<int>&nums, vector<long>&prefix, int &k)
    {
        int l= 0;
        int r= i;
        int best=i;
        while(l<=r)
        {
            int mid= l+(r-l)/2;
            long curr= prefix[i]- ((mid>0)? prefix[mid-1]:0);
            long expect= 1LL* (i-mid+1)* nums[i];
            if(expect-curr<=k)
            {
                best= mid;
                r= mid-1;
            }
            else
            {
                l= mid+1;
            }
        }
        return i-best+1;
    }
    int maxFrequency(vector<int>& nums, int k) 
    {
        int n= nums.size();
        sort(begin(nums),end(nums));
        vector<long>prefix(n,0);
        prefix[0]= nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]= prefix[i-1]+nums[i];
        }
        int ans=1;
        for(int i=0;i<n;i++)
        {
            ans= max(ans,binary(i,nums,prefix,k));
        }
        return ans;
    }
};