class Solution {
public:
    //METHOD-2
    //OPTIMIZED 2 POINTERS..
    int maxArea(vector<int>& height) 
    {
        int n= height.size();
        int ans=0;
        int l=0,r=n-1;
        while(l<r)
        {
            ans= max(ans, min(height[l],height[r])*(r-l));
            if(height[l]<height[r])
            {
                l++;
            }
            else 
            {
                r--;
            }
        }
        return ans;
    }
};
/*
    //METHOD-1
    //BRUTE FORCE..
    int maxArea(vector<int>& height) 
    {
        int n= height.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ans= max(ans, min(height[i],height[j])*(j-i));
            }
        }
        return ans;
    }
*/