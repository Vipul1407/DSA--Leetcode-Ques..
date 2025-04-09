class Solution {
public:
    //METHOD-2
    //UNORDERED MAP..
    int minOperations(vector<int>& nums, int k) 
    {
        unordered_map<int,int>mp;
        int mini=INT_MAX;
        for(auto i:nums)
        {
            mp[i]= 1;
            mini= min(mini,i);
        }
        if(mini<k)
        {
            return -1;
        }
        return  mp.size()- (mini==k);
    }
};
/*
    //METHOD-1
    //UNORDERED SET..
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
*/