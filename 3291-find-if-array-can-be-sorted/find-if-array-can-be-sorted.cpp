class Solution 
{
public:

    bool setbit(int num1, int num2) {
        int cnt1 = 0, cnt2 = 0;
        while (num1 > 0) {
            cnt1 += (num1 & 1);
            num1 >>= 1;
        }
        while (num2 > 0) {
            cnt2 += (num2 & 1);
            num2 >>= 1;
        }
        return cnt1 == cnt2;
    }

    bool canSortArray(vector<int>& nums) 
    {
        int n = nums.size();

        int maxi = nums[0];
        int mini = nums[0];
        int prevmaxi= INT_MIN;

        for (int i = 1; i < n; ++i) 
        {
            if (setbit(nums[i - 1], nums[i])) 
            {
                maxi= max(maxi,nums[i]);
                mini= min(mini,nums[i]);
            } 
            else 
            {
                if (mini<prevmaxi) 
                {
                    return false;
                } 
                prevmaxi= maxi;
                maxi=nums[i];
                mini= nums[i];
            }
        }
        return mini>prevmaxi;
    }
};
