class Solution {
public:
    //METHOD-2
    //BFS..
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& contain, vector<int>& initial) 
    {
        unordered_set<int>st;
        unordered_set<int>vis;
        int ans=0;
        queue<int>q;
        for(int &box: initial)
        {
            if(status[box]==1)
            {
                q.push(box);
            }
            else
            {
                st.insert(box);
            }
        }
        while(q.size())
        {
            int box= q.front();
            q.pop();
            if(vis.count(box))
            {
                continue;
            }
            vis.insert(box);
            ans+= candies[box];

            for(int&b: contain[box])
            {
                if(!vis.count(b) && status[b]==1)
                {
                    q.push(b);
                }
                else
                {
                    st.insert(b);
                }
            }

            for(int &it: keys[box])
            {
                status[it]=1;
                if(!vis.count(it) && st.count(it))
                {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};
/*
    //METHOD-1
    //DFS..
    int dfs(int box,vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& contain, unordered_set<int>&st, unordered_set<int>&vis)
    {
        //if already visited then continue..
        if(vis.count(box))
        {
            return 0;
        }
        if(status[box]==0)
        {
            st.insert(box);
            return 0;
        }
        
        int ans= candies[box];
        vis.insert(box);//mark as visited..
        for(int &b: contain[box])
        {
            ans+= dfs(b,status,candies,keys,contain,st,vis);
        }
        for(int &boxkey: keys[box])
        {
            status[boxkey]=1;
            if(st.count(boxkey))
            {
                ans+= dfs(boxkey,status,candies,keys,contain,st,vis);
            }
        }
        return ans;
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& contain, vector<int>& initial) 
    {
        int ans=0;
        unordered_set<int>st;
        unordered_set<int>vis;
        for(auto box:initial)
        {
            ans+= dfs(box,status,candies,keys,contain,st,vis);
        }
        return ans;
    }
*/