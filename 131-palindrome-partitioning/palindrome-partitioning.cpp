class Solution {
public:
    bool check(string str, int i,int j)
    {
        int n= str.size();
        while(i<=j)
        {
            if(str[i]==str[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    void solve(int i, vector<string> &curr, string &s, vector<vector<string>> &ans)
    {
        if(i==s.size())
        {
            ans.push_back(curr);
            return;
        }

        for(int j=i;j<s.size();j++)
        {
            if(check(s,i,j))
            {
                curr.push_back(s.substr(i,j-i+1));
                solve(j + 1, curr, s, ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        int n= s.size();
        vector<vector<string>>ans;
        vector<string>curr;
        solve(0,curr,s,ans);
        return ans;
    }
};