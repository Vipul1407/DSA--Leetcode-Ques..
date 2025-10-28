class Solution {
public:
    int countValidSelections(vector<int>& nums) 
    {
        int n= nums.size();
        int curr=0;
        int total=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            total+= nums[i];
        }
    
        for(int i=0;i<n;i++)
        {
            curr+= nums[i];
            total-= nums[i];
            if(nums[i]==0)
            {
                if(curr==total)
                {
                    ans+=2;
                }
                if(abs(curr-total)==1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
/*
    //WRONG APPROACH.... 149/584 passed
    class Solution {
    public:
    int countValidSelections(vector<int>& nums) 
    {
        int n= nums.size();
        vector<int>leftsum(n,0);
        vector<int>rightsum(n,0);
        leftsum[0]= nums[0];
        rightsum[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            leftsum[i]= leftsum[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            rightsum[i]= rightsum[i+1]+nums[i];
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                int pleft= i>0 ? leftsum[i-1]:0;
                int pright= i+1<n ? rightsum[i+1]:0;
                if(pleft<=pright)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

*/