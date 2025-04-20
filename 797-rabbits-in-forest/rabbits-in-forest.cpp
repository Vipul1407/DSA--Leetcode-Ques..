class Solution {
public:
    int numRabbits(vector<int>& arr) 
    {
        int n= arr.size();
        unordered_map<int,int>mp;
        for(auto i:arr)
        {
            mp[i]++;
        }
        int ans=0;
        for(auto i:mp)
        {
            int x= i.first;
            int cnt= i.second;
            int grp= ceil((double)cnt/(x+1));
            ans+= grp*(x+1);
        }
        return ans;
    }
};