class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) 
    {
        int n= nums.size();
        vector<int>arr(n-k+1,-1);
        for(int i=0;i<=n-k;i++)
        {
            bool sorted= true;
            for(int j=i;j<i+k-1;j++)
            {
                if(1+nums[j]!=nums[j+1])
                {
                    sorted= false;
                    break;
                }
            }
            if(sorted)
            {
                arr[i]= nums[i+k-1];
            }
        }
        return arr;
    }
};
//BEATS 46%
/*
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>ans(n-k+1,-1);
        bool sorted= true; 
        int maxi= -1;
        for(int i=0;i<n-k+1;i++)
        {
            sorted= true;
            int prev= nums[i];
            maxi= nums[i];
            for(int j=i;j<i+k;j++)
            {
                if(nums[j]<prev)
                {
                    sorted= false;
                    break;
                }
                if(j!=i)
                {
                    if(nums[j]!=prev+1)
                    {
                        sorted= false;
                        break;
                    }
                }
                prev= nums[j];
                maxi= max(maxi,nums[j]);
            }
            if(sorted)
            {
                ans[i]= maxi;
            }
        }
        if(sorted)
        {
            ans[n-k]= maxi;
        }
        return ans;
    }
};
*/