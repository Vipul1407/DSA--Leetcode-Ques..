class Solution 
{
public:

    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& health, string dir) 
    {
        vector<int>arr;
        int n= pos.size();
        //arr storing indexes as we have to return array containing the health of the 
        //remaining robots (in the order they were given in the input) so cannot directly sort pos
        for(int i=0;i<n;i++)
        {
            arr.push_back(i);
        }

        //lamba function
        auto cmp= [&](int i1, int i2)
        {
            return pos[i1]<=pos[i2];
        };
        sort(arr.begin(),arr.end(),cmp);

        //stack to push id
        stack<int>st;
        for(auto id:arr)
        {
            if(dir[id]=='R')
            {
                st.push(id);
            }
            else
            {
                while(!st.empty() && health[id]>0)
                {
                    if(health[id]> health[st.top()])
                    {
                        health[id]--;
                        health[st.top()]=0;
                        st.pop();
                    }
                    else if(health[id]<health[st.top()])
                    {
                        health[st.top()]--;
                        health[id]=0;
                    }
                    else
                    {
                        health[id]=0;
                        health[st.top()]=0;
                        st.pop();
                    }
                }
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(health[i]>0)
            {
                ans.push_back(health[i]);
            }
        }
        return ans;
    }
};