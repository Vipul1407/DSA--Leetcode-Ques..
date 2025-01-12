class Solution {
public:
    bool canBeValid(string s, string locked) 
    {
        int n= locked.size();
        if(n%2==1)
        {
            return false;
        }
        stack<int>st;//storing closed bracket '('
        vector<int>flexible;
        for(int i=0;i<n;i++)
        {
            if(locked[i]=='0')
            {
                flexible.push_back(i);
            }
            else 
            {
                if(s[i]=='(')
                {
                    st.push(i);
                }
                //s[i]= ')' 
                else
                {
                    if(st.size())
                    {
                        st.pop();
                    }
                    //we here need not to check index in flexible if at curr index we have any element in flexible then it means that it has come before
                    else if(flexible.size())
                    {
                        flexible.pop_back();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        //we have index of '(' in st so need ')' after i in flexible..
        while(flexible.size() && st.size() && flexible.back()>st.top())
        {
            st.pop();
            flexible.pop_back();
        }
        if(st.size())
        {
            return false;
        }
        //if even no. of entries then return true 
        return flexible.size()%2==0;
    }
};