class Solution {
public:
    //METHOD-2
    //2 POINTERS OPTIMZED..
    int maxArea(vector<int>& height) 
    {
        int n= height.size();
        int l=0,r=n-1,ans=0;
        while(l<r)
        {
            ans= max(ans, (r-l)*min(height[r],height[l]));
            if(height[l]<=height[r])
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
                ans= max(ans,(j-i)*min(height[i],height[j]));
            }
        }
        return ans;
    }*/