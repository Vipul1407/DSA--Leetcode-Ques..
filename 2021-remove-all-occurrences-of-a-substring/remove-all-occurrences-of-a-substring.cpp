class Solution {
public:
    string removeOccurrences(string s, string part) 
    {
        stack<char>st;
        int n= part.size();
        for(auto i:s)
        {
            st.push(i);
            if(st.size()>=n)
            {
                if(st.top()==part.back())
                {
                    string temp="";
                    for(int i=n-1;i>=0;i--)
                    {
                        temp= st.top()+temp;
                        st.pop();
                    }
                    if(temp!=part)
                    {
                        for(auto i:temp)
                        {
                            st.push(i);
                        }
                    }
                }
            }
        }
        string str="";
        while(st.size())
        {
            str+= st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};