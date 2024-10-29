class Solution {
public:
    char solve(vector<char>&ans, char oper)
    {
        if(oper=='!')
        {
            return ans[0]=='t'? 'f':'t';
        }
        else if(oper=='&')
        {
            for(auto i:ans)
            {
                if(i=='f')
                {
                    return 'f';
                }
            }
            return 't';
        }
        else if(oper=='|')
        {
            for(auto i:ans)
            {
                if(i=='t')
                {
                    return 't';
                }
            }
            return 'f';
        }
        return 't';
    }
    bool parseBoolExpr(string exp) 
    {
        stack<char>st;
        for(auto i:exp)
        {
            if(i==',')
            {
                continue;
            }
            else if(i==')')
            {
                vector<char>ans;
                while(st.size() && st.top()!='(')
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();//to pop out '(' bracket
                char oper= st.top();
                st.pop();
                st.push(solve(ans,oper));
            }
            else
            {
                st.push(i);
            }
        }
        return st.top()=='t'? true:false;
    }
};