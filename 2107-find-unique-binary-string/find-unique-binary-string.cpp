class Solution {
public:
    void solve(vector<string>& nums,string curr,string &res,unordered_set<string>&st,int &n)
    {
        if(res!="")
        {
            return;
        }
        if(curr.size()>n)
        {
            return;
        }
        if(curr.size()==n && st.find(curr)==st.end())
        {
            res= curr;
            st.insert(curr);
            return;
        }
        curr.push_back('0');
        solve(nums,curr,res,st,n);
        curr.pop_back();

        curr.push_back('1');
        solve(nums,curr,res,st,n);
        curr.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) 
    {
        unordered_set<string>st(begin(nums),end(nums));
        string res="";
        string curr="";
        int n= nums[0].size();
        solve(nums,curr,res,st,n);
        return res;
    }
};