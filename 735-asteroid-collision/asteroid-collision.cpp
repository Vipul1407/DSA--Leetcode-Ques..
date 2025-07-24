class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int>st;
        for(auto i:asteroids)
        {
            if(st.empty() || i>0)
            {
                st.push(i);
            }
            else
            {
                while(st.size() && st.top()>0 && st.top()<abs(i))
                {
                    st.pop();
                }
                if(st.size() && st.top()==abs(i))
                {
                    st.pop();
                }
                else
                {
                    if(st.empty() || st.top()<0)
                    {
                        st.push(i);
                    }
                }
            }
        }
        int n= st.size();
        vector<int>ans(n,0);
        while(n>0)
        {
            ans[n-1]= st.top();
            st.pop();
            n--;
        }
        return ans;
    }
};