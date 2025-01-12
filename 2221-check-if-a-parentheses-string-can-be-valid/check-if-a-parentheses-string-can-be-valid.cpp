class Solution {
public:
    //METHOD-2
    //SC=O(1)
    //Without using Stack only variable..
    bool canBeValid(string s, string locked) 
    {
        int n= locked.size();
        if(n%2==1)
        {
            return false;
        }
        //left to right------
        int open=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || locked[i]=='0')
            {
                open++;
            }
            else
            {
                open--;
                if(open<0)
                {
                    return false;
                }
            }
        }
        //right to left-----
        int close=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==')' || locked[i]=='0')
            {
                close++;
            }
            else
            {
                close--;
                if(close<0)
                {
                    return false;
                }
            }
        }
        return open>=0 && close>=0;
    }
};
/*
// METHOD-1
//TC,SC=O(N)
//Using stack and vector..
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
*/