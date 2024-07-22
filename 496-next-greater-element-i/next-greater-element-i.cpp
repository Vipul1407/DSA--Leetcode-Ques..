class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int,int>mp;//to store next greater element 
        stack<int>st;
        int m= nums2.size();

        for(int i=m-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<= nums2[i])
            {
                st.pop();
            }
            mp[nums2[i]]= st.empty()? -1:st.top();
            st.push(nums2[i]);
        }

        vector<int>ans;
        for(auto i:nums1)
        {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};