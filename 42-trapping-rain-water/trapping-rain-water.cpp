class Solution {
public:
    //METHOD-1
    //PREFIX METHOD USING 1VECTORS..
    int trap(vector<int>& height) 
    {
        int n= height.size();
        vector<int>leftmax(n,0);
        leftmax[0]= height[0];
    
        for(int i=1;i<n;i++)
        {
            leftmax[i]= max(leftmax[i-1],height[i]);
        }

        int ans=0;
        int rightmax=0;
        for(int i=n-1;i>=0;i--)
        {
            int val= min(leftmax[i],rightmax);
            ans+= max(0,val-height[i]);
            rightmax= max(rightmax,height[i]);
        }
        return ans;
    }
};
/*
    //METHOD-1
    //PREFIX METHOD USING 2VECTORS..
    int trap(vector<int>& height) 
    {
        int n= height.size();
        vector<int>leftmax(n,0);
        leftmax[0]= height[0];
        vector<int>rightmax(n,0);
        rightmax[n-1]= height[n-1];

        for(int i=1;i<n;i++)
        {
            leftmax[i]= max(leftmax[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            rightmax[i]= max(rightmax[i+1],height[i]);
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            int val= min(rightmax[i],leftmax[i]);
            ans+= max(0,val-height[i]);
        }
        return ans;
    }
*/