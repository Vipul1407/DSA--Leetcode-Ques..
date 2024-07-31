class Solution {
public:
    int minimumDeletions(string s) 
    {
        stack<char>st;
        int cnt=0;
        for(auto i:s)
        {
            if(!st.empty() && i=='a' && st.top()=='b')
            {
                st.pop();
                cnt++;
            }
            else
            {
                st.push(i);
            }
        }
        return cnt;
    }
};