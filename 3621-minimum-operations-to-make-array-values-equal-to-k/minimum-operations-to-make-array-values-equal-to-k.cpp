class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        unordered_set<int>st;
        for(auto i:nums)
        {
            st.insert(i);
        }
        int mini= *min_element(nums.begin(),nums.end());
        if(mini<k)
        {
            return -1;
        }
        return  st.size()- (mini==k);
    }
};