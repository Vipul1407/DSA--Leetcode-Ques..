class Solution {
public:
    //METHOD-3
    //SPACE OPTIMIZED..
    //WITHOUT USING ANY VECTOR..
    int trap(vector<int>& arr) 
    {
        int n= arr.size();
        int l=0,r=n-1;
        int leftmax=0;
        int rightmax=0;
        int water=0;
    
        while(l<r)
        {
            leftmax= max(leftmax,arr[l]);
            rightmax= max(rightmax,arr[r]);
            if(leftmax<=rightmax)
            {
                water+= leftmax-arr[l];
                l++;
            }
            else
            {
                water+= rightmax-arr[r];
                r--;
            }
        }
        return water;
    }
};
/*
    //METHOD-1
    //USING 2 VECTORS..
    int trap(vector<int>& arr) 
    {
        int n= arr.size();
        vector<int>leftmax(n,0);
        leftmax[0]= arr[0];
        vector<int>rightmax(n,0);
        rightmax[n-1]= arr[n-1];
        for(int i=1;i<n;i++)
        {
            leftmax[i]= max(leftmax[i-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            rightmax[i]= max(rightmax[i+1],arr[i]);
        }
        int water=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<leftmax[i] && arr[i]<rightmax[i])
            {
                water+= min(leftmax[i],rightmax[i])-arr[i];
            }
        }
        return water;
    }

    //METHOD-2
    //USING 1 VECTOR..
    int trap(vector<int>& arr) 
    {
        int n= arr.size();
        vector<int>rightmax(n,0);
        rightmax[n-1]= arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightmax[i]= max(rightmax[i+1],arr[i]);
        }

        int water=0;
        int leftmax= arr[0];
        for(int i=0;i<n;i++)
        {
            leftmax= max(leftmax,arr[i]);
            if(arr[i]<leftmax && arr[i]<rightmax[i])
            {
                water+= min(leftmax,rightmax[i])-arr[i];
            }
        }
        return water;
    }
*/