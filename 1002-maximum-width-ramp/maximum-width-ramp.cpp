class Solution {
public:
    int maxWidthRamp(vector<int>& nums) 
    {
        int n= nums.size();
        stack<int>st;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(st.empty() || nums[i]<nums[st.top()])
            {
                st.push(i);
            }
        } 
        for(int j=n-1;j>=0;j--)
        {
            while(!st.empty() && nums[j]>=nums[st.top()])
            {
                ans= max(ans,j-st.top());
                st.pop();
            }
        }
        return ans;
    }
};

