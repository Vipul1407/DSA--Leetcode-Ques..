class Solution {
public:
    void subset(vector<int>& nums,int i,int temp,int &cnt,int tar)
    {
        if(i==nums.size())
        {
            if(temp==tar)
                cnt++;
            return;
        }
        subset(nums,i+1,temp,cnt,tar);
        subset(nums,i+1,temp|nums[i],cnt,tar);
    }
    int countMaxOrSubsets(vector<int>& nums) 
    {
        int tar=0;
        for(auto i:nums)
        {
            tar|=i;
        }
        int cnt=0;
        subset(nums,0,0,cnt,tar);
        return cnt;
    }
};