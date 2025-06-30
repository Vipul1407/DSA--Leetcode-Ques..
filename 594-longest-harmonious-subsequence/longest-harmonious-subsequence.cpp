class Solution {
public:
    //METHOD-1
    //Using Unordered_Map
    int findLHS(vector<int>& nums) 
    {
        int n= nums.size();
        int ans=0;
        unordered_map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        for(auto i:mp)
        {
            int next= 0;
            //do not use mp[i.first+1]>0 as it will create new entry in it...
            if(mp.count(i.first+1))
            {
                next= i.second+ mp[i.first+1];
                ans= max(ans,next);
            }
        }
        return ans;
    }
};