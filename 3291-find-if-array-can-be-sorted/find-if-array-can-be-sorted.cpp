class Solution {
public:
    bool equalsetbit(int a,int b)
    {
        int cnt1=0;
        int cnt2=0;
        while(a>0)
        {
            if(1 & a)
            {
                cnt1++;
            }
            a>>=1;//a= a>>1
        }
        while(b>0)
        {
            if(1 & b)
            {
                cnt2++;
            }
            b>>=1;//b= b>>1
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