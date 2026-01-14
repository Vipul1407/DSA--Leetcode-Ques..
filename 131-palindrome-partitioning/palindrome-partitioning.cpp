class Solution {
public:
    bool palindrome(string &a)
    {
        int l=0;
        int r= a.size()-1;
        while(l<=r)
        {
            if(a[l]!=a[r])
            {
                return false;
            }
            l++;r--;
        }
        return true;
    }
    void rec(int i, string &s, vector<string>curr, vector<vector<string>>&ans)
    {
        int n= s.size();
        if(i==n)
        {
            ans.push_back(curr);
            return;
        }
        for(int j=i;j<n;j++)
        {
            string newstr= s.substr(i,j-i+1);
            if(palindrome(newstr))
            {
                curr.push_back(newstr);
                rec(j+1,s,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>>ans;
        vector<string>curr;
        rec(0,s,curr,ans);
        return ans;
    }
};