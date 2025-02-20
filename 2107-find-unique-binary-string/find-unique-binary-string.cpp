class Solution {
public:
    void solve(string &curr, int k, unordered_set<string>&st, string &ans, bool &flag)
    {
        if(flag==true || curr.length()>k)
        {
            return;
        }
        if(curr.length()==k && st.find(curr)==st.end())
        {
            ans=curr;
            flag= true;
            return;
        }
        curr.push_back('0');
        solve(curr,k,st,ans,flag);
        curr.pop_back();

        curr.push_back('1');
        solve(curr,k,st,ans,flag);
        curr.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) 
    {
        unordered_set<string>st;
        int k= nums[0].size();
        for(auto i:nums)
        {
            st.insert(i);
        }
        string curr;
        string ans="";
        bool flag= false;
        solve(curr,k,st,ans,flag);
        return ans;
    }
};