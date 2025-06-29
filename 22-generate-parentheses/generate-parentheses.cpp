class Solution {
public:
    //METHOD-2
    //OPTIMIZED...
    //TC= O(2^(N))  where N= 2*n
    void solve(string curr, int n, int open, int close, vector<string>&ans)
    {
        if(open==n && close==n)
        {
            ans.push_back(curr);
            return;
        }
        if(open<n)
        {
            curr.push_back('(');
            solve(curr,n,open+1,close,ans);
            curr.pop_back();
        }
        if(close<open)
        {
            curr.push_back(')');
            solve(curr,n,open,close+1,ans);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string>ans;
        solve("",n,0,0,ans);
        return ans;
    }
};
/*
    //METHOD-1
    //Backtracking..
    //TC= O(N* 2^(N))  where N= 2*n
    bool valid(string &curr)
    {
        int cnt=0;
        for(auto i:curr)
        {
            if(i=='(')
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            //to handle this case.. )()(
            if(cnt<0)
            {
                return false;
            }
        }
        return cnt==0;
    }
    void solve(string curr, int n, int len, vector<string>&ans)
    {
        if(len==2*n)
        {
            if(valid(curr))
            {
                ans.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        solve(curr,n,len+1,ans);
        curr.pop_back();

        curr.push_back(')');
        solve(curr,n,len+1,ans);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string>ans;
        solve("",n,0,ans);
        return ans;
    }
*/