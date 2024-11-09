class Solution {
public:
    bool equalsetbit(int a,int b)
    {
        int cnt1=0;
        int cnt2=0;
        while(a>0)
        {
            a&=(a-1);//a= a&(a-1);
            cnt1++;
        }
        while(b>0)
        {
            b&=(b-1);//b= b&(b-1);
            cnt2++;
        }
        return cnt1==cnt2;//return true if they have same no. of set bits
    }
    bool canSortArray(vector<int>& nums) 
    {
        int prevmaxi= -1;//INT_MIN
        int maxi= nums[0];
        int mini= nums[0];
        int n= nums.size();
        for(int i=1;i<n;i++)
        {
            //same group..update maxi,mini
            if(equalsetbit(nums[i-1],nums[i]))
            {
                maxi= max(maxi,nums[i]);
                mini= min(mini,nums[i]);
            }
            //different group..start new maxi,mini and update prevmaxi= maxi
            else
            {
                // array will we sorted when prevmaxi<mini
                if(prevmaxi>mini)
                {
                    return false;
                }
                prevmaxi= maxi;
                maxi= nums[i];
                mini= nums[i];
            }
        }
        //to handle for last element
        return mini>prevmaxi;
    }
};

/*
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
*/