class Solution {
public:
    bool equalsetbit(int num1, int num2)
    {
        int cnt1 = 0;
        int cnt2 = 0;
        while (num1 > 0)
        {
            if (num1 & 1)
            {
                cnt1++;
            }
            num1 >>= 1; // right shift by 1
        }
        while (num2 > 0)
        {
            if (num2 & 1)
            {
                cnt2++;
            }
            num2 >>= 1; // right shift by 1
        }
        return cnt1 == cnt2;
    }
    //BUBBLE SORT..
    bool canSortArray(vector<int>& nums) 
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int flag=1;
            for(int j=0;j<n-i-1;j++)
            {
                if(nums[j]<=nums[j+1])
                {
                    continue;
                }
                //nums[j]>nums[j+1]
                else
                {
                    if(equalsetbit(nums[j],nums[j+1]))
                    {
                        swap(nums[j],nums[j+1]);
                        flag=0;
                    }
                    else
                    {
                        //we cannot swap hence array cannot be sorted..
                        return false;
                    }
                }
            }
            //array is already sorted..
            if(flag==1)
            {
                break;
            }
        }
        return true;
    }
};