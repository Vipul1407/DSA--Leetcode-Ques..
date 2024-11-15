class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) 
    {
        int n= arr.size();
        //start i from starting
        int i=0;
        int j=n-1;
        while(j>0 && arr[j]>=arr[j-1])
        {
            j--;
        }
        if(j==0)
        {
            return 0;
        }
        int todelete= j;
        while(i<n && (i==0 || arr[i]>=arr[i-1]))
        {
            while(j<n && arr[i]>arr[j])
            {
                j++;
            }
            todelete= min(todelete, j-i-1);
            i++;
        }
        return todelete;
    }
};