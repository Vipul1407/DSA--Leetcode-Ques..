class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        int n= time.size();
        vector<int>mp(60,0);
        int cnt=0;
        for(auto i:time)
        {
            int tofind= (60-(i%60))%60;
            cnt+= mp[tofind];
            mp[i%60]++;
        }
        return cnt;
    }
};