class Solution {
public:
    void solve(int start, int &n, int k, vector<int>&temp, vector<vector<int>>&ans)
    {
        if(k==0)
        {
            ans.push_back(temp);
            return;
        }
        if(start>n)
        {
            return;
        }
        //include start element...
        temp.push_back(start);
        solve(start+1,n,k-1,temp,ans);
        //exclude ...
        temp.pop_back();
        solve(start+1,n,k,temp,ans);
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(1,n,k,temp,ans);
        return ans;
    }
};