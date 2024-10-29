class Solution {
public:

    void solve(int i,int cnt,int &maxcnt,string &s,unordered_set<string>&st)
    {
        int n= s.size();
        //slight optimizing code..
        if(cnt+ n-i <=maxcnt)
        {
            return;
        }
        if(i>=n)
        {
            maxcnt= max(maxcnt,cnt);
            return;
        }
        for(int j=i;j<n;j++)
        {
            string sub= s.substr(i,j-i+1);
            if(st.find(sub)==st.end())
            {
                st.insert(sub);
                solve(j+1,cnt+1,maxcnt,s,st);
                st.erase(sub);//backtracking...
            }
        }
    
    }
    int maxUniqueSplit(string s) 
    {
        unordered_set<string>st;
        int cnt=0;
        int maxcnt=0; 
        solve(0,cnt,maxcnt,s,st);
        return maxcnt;
    }
};