class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) 
    {
        int n= arrays.size();
        int ans= INT_MIN;
        int pmin= arrays[0].front();
        int pmax= arrays[0].back();
        for(int i=1;i<n;i++)
        {
            ans= max(ans, arrays[i].back()-pmin);
            ans= max(ans, pmax-arrays[i].front());
            pmin= min(pmin, arrays[i].front());
            pmax= max(pmax, arrays[i].back());
        }
        return  ans;
    }
};