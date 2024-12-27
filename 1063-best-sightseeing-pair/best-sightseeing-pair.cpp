class Solution {
public:
    //METHOD-1
    //Using prefix max vector for arr[i]+i 
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        int n= values.size();
        int ans= 0;
        int pref= values[0];
        for(int j=1;j<n;j++)
        {
            ans= max(ans, pref+values[j]-j);
            pref= max(pref,values[j]+j);
        }
        return ans;
    }
};