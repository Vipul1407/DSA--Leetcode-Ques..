class Solution {
public:
    string reverseParentheses(string s) 
    {
        stack<char>st;
        for(auto c:s)
        {
            if(c!=')')
            {
                st.push(c);
            }
            else
            {
                string temp="";
                while(!st.empty() && st.top()!='(')
                {
                    temp+= st.top();
                    st.pop();
                }
                st.pop();//to remove '('
                for(auto i:temp)
                {
                    st.push(i);
                }
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans= st.top()+ans;//to avoid reversal
            st.pop();
        }
        return ans;
    }
};