class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) 
    {
        long long cnt=0;
        int n= hours.size();
        vector<int>mp(24,0);
        for(auto i:hours)
        {
            int tofind= (24-(i%24))%24;
            cnt+= mp[tofind];
            mp[i%24]++;
        }
        return cnt;
    }
};