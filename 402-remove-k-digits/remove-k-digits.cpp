class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        stack<char>st;
        string ans="";

        for(auto i:num)
        {
            while(st.size() && k>0 && st.top()>i)
            {
                st.pop();
                k--;
            }
            st.push(i);
        }
        while(k>0)
        {
            st.pop();
            k--;
        }
        while(st.size())
        {
            ans+= st.top();
            st.pop();
        }
        while(ans.size() && ans.back()=='0')
        {
            ans.pop_back();
        }
        if(ans=="")
        {
            return "0";
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};