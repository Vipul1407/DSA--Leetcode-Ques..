class Solution {
public:
    //METHOD-3
    //OPTIMIZED USING 1 LOOP + 2 POINTERS..
    //TC= O(N^3)
    int triangleNumber(vector<int>& nums) 
    {
        int n= nums.size();
        int ans=0;
        sort(begin(nums),end(nums));
        
        for(int k=n-1;k>=2;k--)
        {
            int i=0;
            int j=k-1;
            while(i<j)
            {
                int sum= nums[i]+nums[j];
                if(sum>nums[k])
                {
                    ans+= j-i;
                    j--;
                }
                else
                {
                    i++;
                }
            }
        }
        return ans;
    }
};
/*
    //METHOD-1
    //BRUTE FORCE..
    //TC= O(N^3)
    int triangleNumber(vector<int>& nums) 
    {
        int n= nums.size();
        int ans=0;
        for(int i=0;i<=n-3;i++)
        {
            for(int j=i+1;j<=n-2;j++)
            {
                for(int k=j+1;k<=n-1;k++)
                {
                    if(nums[i]+nums[j]>nums[k])
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }

    //METHOD-2
    //BINARY SEARCH..
    //TC= O(N^2 * LOGN)
    int binary(int i, int j, vector<int>& nums)
    {
        int sum= nums[i]+nums[j];
        int l= j+1;
        int r= nums.size()-1;
        while(l<=r)
        {
            int mid= l+(r-l)/2;
            if(sum>nums[mid])
            {
                l= mid+1;//to increase the size..
            }
            else
            {
                r= mid-1;
            }
        }
        return r-j;
    }
    int triangleNumber(vector<int>& nums) 
    {
        int n= nums.size();
        int ans=0;
        sort(begin(nums),end(nums));
        for(int i=0;i<=n-3;i++)
        {
            for(int j=i+1;j<=n-2;j++)
            {
                ans+= binary(i,j,nums);
            }
        }
        return ans;
    }
*/