class Solution {
public:
    //lower bound gives smallest idx of >=x
    //upper bound gives smallest idx of >x

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
            int ub= upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
            int lb= lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
            ans+= (ub-lb);
        }
        return ans;
    }
};