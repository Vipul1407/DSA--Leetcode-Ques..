class Solution {
public:
    int minLength(string s) 
    {
        stack<char>st;
        for(auto i:s)
        {
            if(i=='D')
            {
                if(st.size() && st.top()=='C')
                {
                    st.pop();
                }
                else
                {
                    st.push(i);
                }
            }
            else if(i=='B')
            {
                if(st.size() && st.top()=='A')
                {
                    st.pop();
                }
                else
                {
                    st.push(i);
                }
            }
            else
            {
                st.push(i);
            }
        }
        return st.size();
    }
};