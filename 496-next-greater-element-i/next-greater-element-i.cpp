class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int,int>mp;   
        vector<int>ans; 
        stack<int>st;
        int n= nums2.size();
        for(int i=n-1;i>=0;i--)
        {
            int ele= nums2[i];
            while(st.size() && st.top()<=ele)
            {
                st.pop();
            }
            mp[ele]= st.empty()?-1:st.top();
            st.push(ele);
        }
        for(auto ele:nums1)
        {
            ans.push_back(mp[ele]);
        }
        return ans;
    }
};