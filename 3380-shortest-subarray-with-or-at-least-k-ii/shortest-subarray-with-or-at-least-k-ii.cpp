class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) 
    {
        int n= nums.size();
        int l=0,r=0;
        int curr_or=0;
        int minlen= INT_MAX;
        vector<int>bitpos(30,0);//assuming 32bit or can calculate digits= log2(num)+1, here log2(10^9)+1= 30
        while(r<n)
        {
            curr_or |=nums[r];
            int temp= nums[r];
            for(int i=0;i<30;i++)
            {
                if(temp & (1<<i))
                {
                    bitpos[i]++;
                }
            }
            //shrink window.. by deducting only if the se bit of nums[l] effect our curr_or
            while(curr_or>=k && l<=r)
            {
                minlen= min(minlen,r-l+1);
                for(int i=0;i<30;i++)
                {
                    if(nums[l] & (1<<i))
                    {
                        bitpos[i]--;
                        if(bitpos[i]==0)
                        {
                            //now we have to subtract value of that bit from our curr_or 
                            //curr_or &= ~(1<<i);
                            curr_or -= (1<<i);
                        }
                    }
                }
                l++;
            }
            r++;
        }
        return minlen==INT_MAX? -1:minlen;
    }
};