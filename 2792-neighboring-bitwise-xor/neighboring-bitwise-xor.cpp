class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) 
    {
        int n= derived.size();
        vector<int>original(n,0);
        for(int i=1;i<n;i++)
        {
            original[i]= derived[i-1]^original[i-1];
        }
        return original[0]^original[n-1]==derived[n-1];
    }
};