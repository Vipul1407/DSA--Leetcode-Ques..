class Solution {
public:
    string reverseParentheses(string s) 
    {
        stack<char>st;
        int i=0;
        int n= s.length();
        while(i<n)
        {
            if(s[i]!=')')
            {
                st.push(s[i]);
            }
            else
            {
                queue<char>q;
                while(!st.empty() && st.top()!='(')
                {
                    q.push(st.top());
                    st.pop();
                }
                
                st.pop();//to remove '('

                while(!q.empty())
                {
                    st.push(q.front());
                    q.pop();
                }
            }
            //in each iteration increase i
            i++;
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