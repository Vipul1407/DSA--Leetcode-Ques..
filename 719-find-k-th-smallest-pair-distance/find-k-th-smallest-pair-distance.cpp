class Solution {
public:
    int numberofpairs(vector<int>& nums, int mid)
    {
        int i=0,j=0,n=nums.size(),cnt=0;
        while(j<n)
        {
            //shrink the curr window..
            //we want diff less than mid..
            while(i<j && nums[j]-nums[i]> mid)
            {
                i++;
            }
            cnt+= j-i;//will not add 1
            j++;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) 
    {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        //finding max value..
        int e= nums[n-1]-nums[0];
        //finding min value..
        int s= INT_MAX;
        for(int i=1;i<n;i++)
        {
            s= min(s,nums[i]-nums[i-1]);
        }
        
        int ans;
        while(s<=e)
        {
            int mid= s+(e-s)/2;
            //we have to find kth smallest diff. so we need atleast k pairs..
            if(numberofpairs(nums,mid)>=k)
            {
                ans= mid;
                e=mid-1;//to get exact kth value
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
    }
};