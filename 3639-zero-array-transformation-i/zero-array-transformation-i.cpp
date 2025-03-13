class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& quer) 
    {
        int n= nums.size();
        vector<int>pref(n,0);
        for(auto i:quer)
        {
            int s= i[0];
            int e= i[1];
            pref[s]++;
            if(e+1<n)
            {
                pref[e+1]--;
            }
        }
        for(int i=1;i<n;i++)
        {
            pref[i]+= pref[i-1];
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]-pref[i]>0)
            {
                return false;
            }
        }
        //if all elements after nums[i]-pref[i] <=0 then retun true...
        return true;
    }
};