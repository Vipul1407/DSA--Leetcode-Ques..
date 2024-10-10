class Solution {
public:
    int maxWidthRamp(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>minifirst(n,0);//prefix min array
        minifirst[0]=nums[0];

        vector<int>maxilast(n,0);//suffix max array
        maxilast[n-1]=nums[n-1];

        for(int i=1;i<n;i++)
        {
            minifirst[i]= min(minifirst[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            maxilast[i]= max(maxilast[i+1],nums[i]);
        }

        int ans=0;
        int i=0;
        int j=0;
        while(j<n)
        {
            if(minifirst[i]<= maxilast[j])
            {
                ans= max(ans,j-i);
                j++;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};