class Solution {
public:
    //METHOD-1
    //Using prefix max vector for arr[i]+i 
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        int n= values.size();
        vector<int>pref(n,0);
        pref[0]= values[0];
        for(int i=1;i<n;i++)
        {
            pref[i]= max(pref[i-1],values[i]+i);
        }
        int ans= 0;
        for(int j=1;j<n;j++)
        {
            ans= max(ans, pref[j-1]+values[j]-j);
        }
        return ans;
    }
};