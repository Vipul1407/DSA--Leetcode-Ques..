class Solution {
public:
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
};