class Solution {
public:
    //METHOD-3
    //2 POINTERS..
    int trap(vector<int>& height) 
    {
        int n= height.size();
        int ans=0,l=0,r=n-1;
        int lmax=0,rmax=0;
        while(l<r)
        {
            if(height[l]<=height[r])
            {
                if(lmax>height[l])
                {
                    ans+= lmax-height[l];
                }
                else
                {
                    lmax= max(lmax,height[l]);
                }
                l++;
            }
            else
            {
                if(rmax>height[r])
                {
                    ans+= rmax-height[r];
                }
                else
                {
                    rmax= max(rmax,height[r]);
                }
                r--;
            }
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

    //METHOD-2
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
*/