class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) 
    {
        unordered_set<int>st;
        for(auto i:arr1)
        {
            //for eg. we have common prefix of 12345 and 123 we have to insert till 12345 and 12345/10= 1234 only becoz we already have numbers below this in set due to all prefixes of 123
            while(st.find(i)==st.end() && i>0)
            {
                st.insert(i);
                i/=10;
            }
        }
        int ans=0;
        for(auto i:arr2)
        {
            while(st.find(i)==st.end() && i>0)
            {
                i/=10;
            }
            if(i>0)
                ans= max(ans, static_cast<int>(log10(i))+1);
        }
        return ans;
    }
};