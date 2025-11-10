class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int n= nums.size();
        stack<int>st;
        int ans=0;
        for(auto i:nums)
        {  
            while(st.size() && i<st.top())
            {
                st.pop();
            }
            if(i==0)
            {
                continue;
            }
            if(st.empty() || st.top()<i)
            {
                ans++;
                st.push(i);
            }
        }
        return ans;
    }
};