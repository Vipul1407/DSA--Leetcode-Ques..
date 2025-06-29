class Solution {
public:
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
};