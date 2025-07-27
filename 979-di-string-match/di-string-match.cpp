class Solution {
public:
    //METHOD-2
    //OPTIMZED USING STACK..
    vector<int> diStringMatch(string s) 
    {
        int n= s.size();
        vector<int>ans;
        stack<int>st;
        int num=0;
        for(int i=0;i<=n;i++)
        {
            st.push(num);
            num++;
            if(i==n || s[i]=='I')
            {
                while(st.size())
                {
                    ans.push_back(st.top());
                    st.pop();
                }
            }
        }
        while(st.size())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};