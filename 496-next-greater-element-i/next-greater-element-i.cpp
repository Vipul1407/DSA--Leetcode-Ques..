class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n= nums1.size();
        int m= nums2.size();
        vector<int>vec(m,0);
        stack<int>st;
       unordered_map<int,int>mp;
        for(int i=m-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<= nums2[i])
            {
                st.pop();
            }
            vec[i]= st.empty()? -1: st.top();
            st.push(nums2[i]);
            mp[nums2[i]]=i;
        }

        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            ans[i]=  vec[mp[nums1[i]]];
        }
        return ans;
    }
};