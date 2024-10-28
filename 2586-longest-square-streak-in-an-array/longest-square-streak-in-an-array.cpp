class Solution {
public:
    int longestSquareStreak(vector<int>& nums) 
    {
        unordered_set<int>st;
        for(auto i:nums)
        {
            st.insert(i);
        }
        int ans=1;
        for(auto i:nums)
        {
            int cnt=1;
            long long curr=i;
            while(curr*curr<= INT_MAX && st.find(curr*curr)!=st.end())
            {
                curr*=curr;
                cnt++;
            }
            ans= max(ans,cnt);
        }
        return ans==1? -1:ans;
    }
};