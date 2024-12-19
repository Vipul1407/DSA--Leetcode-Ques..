class Solution {
public:
    //METHOD-2
    //MONOTONIC STACK
    int maxChunksToSorted(vector<int>& arr) 
    {
        stack<int>st;
        int largest= INT_MIN;
        
        for(int i:arr)
        {
            largest= max(largest, i);
            while(st.size() && st.top()>i)
            {
                st.pop();
            }
            st.push(largest);
        }
        return st.size();
    }
};

/*

// METHOD-1
// PREFIX SUM
int maxChunksToSorted(vector<int> &arr)
{
    int n = arr.size();
    vector<int> leftmax(n, INT_MIN);
    leftmax[0] = arr[0];
    vector<int> rightmin(n, INT_MAX);
    rightmin[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        leftmax[i] = max(leftmax[i - 1], arr[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        rightmin[i] = min(rightmin[i + 1], arr[i]);
    }
    int maxchunks = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // until leftmax is greater equal to rightmin, we know that there exist a element on right that must comes in left chunk
        //  so when when we got less than equal means that now we can form a chunk
        if (leftmax[i] <= rightmin[i + 1])
        {
            maxchunks++;
        }
    }
    return maxchunks + 1;
}
*/