class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) 
    {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        int demand= INT_MIN;
        int cnt=0;
        for(auto i:nums)
        {
            int lower= i-k;
            int higher= i+k;
            if(demand<lower)
            {
                demand= lower;
                cnt++;
            }
            //lies b/w range then give demand value 1more than last given..
            else if(demand<higher)
            {
                demand++;
                cnt++;
            }
        }
        return cnt;
    }
};