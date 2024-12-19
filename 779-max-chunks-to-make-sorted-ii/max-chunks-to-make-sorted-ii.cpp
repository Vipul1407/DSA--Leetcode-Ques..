class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int n= arr.size();
        vector<int>leftmax(n,INT_MIN);
        leftmax[0]= arr[0];
        vector<int>rightmin(n,INT_MAX);
        rightmin[n-1]= arr[n-1];
        for(int i=1;i<n;i++)
        {
            leftmax[i]= max(leftmax[i-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            rightmin[i]= min(rightmin[i+1],arr[i]);
        }
        int maxchunks=0;
        for(int i=0;i<n-1;i++)
        {
            if(leftmax[i] <= rightmin[i+1])
            {
                maxchunks++;
            }
        }
        return maxchunks+1;
    }
};