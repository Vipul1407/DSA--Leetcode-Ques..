class Solution {
public:
    int maxProfit(vector<int>& nums) 
    {
        int n= nums.size();
        int buy= nums[0];
        int profit=0;
        for(int i=1;i<n;i++)
        {
            profit= max(profit,nums[i]-buy);
            buy= min(buy,nums[i]);
        }
        return profit;
    }
};