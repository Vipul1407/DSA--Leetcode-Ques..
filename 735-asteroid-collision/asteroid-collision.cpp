class Solution {
public:
    vector<int> asteroidCollision(vector<int>& aster) 
    {
        stack<int>st;
        for(auto i:aster)
        {
            if(st.empty() || i>0)
            {
                st.push(i);
            }
            else
            {
                while(!st.empty() && st.top()>0 && st.top()< abs(i))
                {
                    st.pop();
                }
                if(!st.empty() && st.top()==abs(i))
                {
                    st.pop();
                }
                else //st.top()> abs(i) then no need to pop from stack
                {
                    if(st.empty() || st.top()<0)
                    {
                        st.push(i);
                    }
                }
            }
        }
        int n=st.size();
        vector<int>res(n);
        for(int i=n-1;i>=0;i--)
        {
            res[i]=st.top();
            st.pop();
        }
        return res;
    }
};