class Solution {
public:
    //METHOD-2
    //BFS..
    //TC= n*(10*n)= n^2 since 10 additions can be applied to a single digit hence 10n and outer n for rotation
    //SC= n^2
    void rotate(string &s, int b)
    {
        reverse(begin(s),end(s));
        reverse(begin(s),begin(s)+b);
        reverse(begin(s)+b,end(s));
    }
    string findLexSmallestString(string s, int a, int b) 
    {
        unordered_set<string>st;
        string ans= s;
        queue<string>q;
        q.push(s);
        st.insert(s);
        while(q.size())
        {
            auto temp= q.front();
            ans= min(ans,temp);
            q.pop();
            //adding a to odd indexes..
            string curr1= temp;
            for(int i=1;i<s.size();i+=2)
            {
                curr1[i]= (curr1[i]-'0'+a)%10 +'0';
            }
            if(!st.count(curr1))
            {
                q.push(curr1);
                st.insert(curr1);
            }
            //rotate by b..
            string curr2= temp;
            rotate(curr2,b);
            if(!st.count(curr2))
            {
                q.push(curr2);
                st.insert(curr2);
            }
        }
        return ans;
    }
};
/*
    //METHOD-1
    //DFS..
    //TC= n*(10*n)= n^2 since 10 additions can be applied to a single digit hence 10n and outer n for rotation
    //SC= n^2
    void rotate(string &s, int b)
    {
        reverse(begin(s),end(s));
        reverse(begin(s),begin(s)+b);
        reverse(begin(s)+b,end(s));
    }
    void dfs(string s, string &ans, int &a, int &b, unordered_set<string>&st)
    {
        st.insert(s);
        ans= min(ans,s);
        //adding a to odd indexes..
        string curr1= s;
        for(int i=1;i<s.size();i+=2)
        {
            curr1[i]= (curr1[i]-'0'+a)%10 +'0';
        }
        if(!st.count(curr1))
        {
            dfs(curr1,ans,a,b,st);
        }
        //rotate by b..
        string curr2= s;
        rotate(curr2,b);
        if(!st.count(curr2))
        {
            dfs(curr2,ans,a,b,st);
        }
    }
    string findLexSmallestString(string s, int a, int b) 
    {
        unordered_set<string>st;
        string ans= s;
        dfs(s,ans,a,b,st);
        return ans;
    }
*/