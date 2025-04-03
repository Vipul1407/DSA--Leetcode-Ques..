class Solution {
public:
    //METHOD-3
    //BETTER APPROACH USING 1 VECTOR ONLY..
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n= nums.size();
        long long ans=0;
        vector<int>rightmax(n,0);  
        for(int i=n-2;i>=0;i--)
        {
            rightmax[i]= max(rightmax[i+1],nums[i+1]);
        }
        int leftmax=0;
        for(int i=1;i<n-1;i++)
        {
            leftmax= max(leftmax,nums[i-1]);  
            ans= max(ans,(long long)(leftmax-nums[i])*rightmax[i]);
        }
        return ans;
    }
};
/*
//METHOD-1
    //BRUTE FORCE..
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n= nums.size();
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    ans= max(ans,(long long)(nums[i]-nums[j])*nums[k]);
                }
            }
        }    
        return ans;
    }

    //METHOD-2
    //BETTER APPROACH USING 2 VECTORS PREFIXMAX, SUFFIXAMX..
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n= nums.size();
        long long ans=0;
        vector<int>leftmax(n,0);
        vector<int>rightmax(n,0);

        for(int i=1;i<n;i++)
        {
            leftmax[i]= max(leftmax[i-1],nums[i-1]);
        }    
        for(int i=n-2;i>=0;i--)
        {
            rightmax[i]= max(rightmax[i+1],nums[i+1]);
        }
        for(int i=1;i<n-1;i++)
        {
            ans= max(ans,(long long)(leftmax[i]-nums[i])*rightmax[i]);
        }
        return ans;
    }
*/