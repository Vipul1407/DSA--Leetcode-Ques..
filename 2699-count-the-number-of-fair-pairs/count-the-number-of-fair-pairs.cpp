class Solution {
public:
    //METHOD-3
    //lower bound gives smallest idx of >=x
    int lb(int i,int ele,vector<int>& nums)
    {
        int s=i+1;
        int e= nums.size()-1;
        while(s<=e)
        {
            int mid= (s+e)/2;
            if(nums[mid]>=ele)
            {
                e= mid-1;
            }
            else
            {
                s= mid+1;
            }
        }
        return s;
    }
    //upper bound gives smallest idx of >x
    int ub(int i,int ele,vector<int>& nums)
    {
        int s=i+1;
        int e= nums.size()-1;
        while(s<=e)
        {
            int mid= (s+e)/2;
            if(nums[mid]>ele)
            {
                e= mid-1;
            }
            else
            {
                s= mid+1;
            }
        }
        return s;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        sort(nums.begin(),nums.end());
        long long ans=0;
        int n=nums.size();
        // lower <= arr[i]+arr[j] <=upper
        //we are iterating over arr to get arr[i] 
        // lower <=x<= upper
        // now find upper_bound of lower
        // and find lower_bound of upper
        // minus upper_bound and lower_bound for every element will give req. ans
        for(int i=0;i<n-1;i++)
        {
            //ub and lb will start from their next index.. 
            int upperb= ub(i,upper-nums[i],nums);
            int lowerb= lb(i,lower-nums[i],nums);
            ans+= (upperb-lowerb);
        }
        return ans;
    }
};
/*
    //METHOD-2
    //OPTIMIZED USING LOWER, UPPER BOUND..
    //TC= O(NLOGN)
    long long countFairPairs(vector<int>& arr, int lower, int upper) 
    {
        int n= arr.size();
        sort(arr.begin(),arr.end());
        long long cnt=0;
        for(int i=0;i<n;i++)
        {
            int lb= lower_bound(arr.begin()+i+1,arr.end(),lower-arr[i])- arr.begin();
            int ub= upper_bound(arr.begin()+i+1,arr.end(),upper-arr[i])- arr.begin();
            cnt+= ub-lb;
        }
        return cnt;
    }

//METHOD-1
// BRUTE FORCE..
long long countFairPairs(vector<int> &arr, int lower, int upper)
{
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] >= lower && arr[i] + arr[j] <= upper)
            {
                cnt++;
            }
        }
    }
    return cnt;
}
*/