class Solution {
public:
    //METHOD-2
    //BFS..
    //TC= O(V+E) as we need to find shortest path..
    int openLock(vector<string>& deadends, string tar)
    {
        unordered_set<string>st(begin(deadends),end(deadends));
        unordered_set<string>vis;
        if(st.count(tar) || st.count("0000"))
        {
            return -1;
        }
        vis.insert("0000");
        queue<pair<string,int>>q;
        q.push({"0000",0});
        int ans=INT_MAX;

        while(q.size())
        {
            string curr= q.front().first;
            int cnt= q.front().second;
            if(curr==tar)
            {
                ans= min(ans,cnt);
            }
            q.pop();

            for(int k=0;k<4;k++)
            {
                string temp1= curr;
                string temp2= curr;
                temp1[k]= ((temp1[k]-'0'+1)%10)+'0';
                if(!st.count(temp1) && !vis.count(temp1))
                {
                    q.push({temp1,cnt+1});
                    vis.insert(temp1);
                }
                temp2[k]= ((temp2[k]-'0'-1+10)%10)+'0';
                if(!st.count(temp2) && !vis.count(temp2))
                {
                    q.push({temp2,cnt+1});
                    vis.insert(temp2);
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
/*
    //METHOD-1
    //DFS..
    //TC= O(B^D) exponential
    //TLE...
    void dfs(string &curr, string &tar, unordered_set<string>&st, unordered_set<string>&vis, int cnt, int &ans)
    {
        if(st.count(curr) || vis.count(curr))
        {
            return;
        }
        if(cnt>=ans)
        {
            return;
        }
        if(curr.size()>tar.size())
        {
            return;
        }
        if(curr==tar) 
        {
            ans= min(ans,cnt);
            return;
        }
        vis.insert(curr);
        
        for(int k=0;k<4;k++)
        {
            //changing the 4 digit..
            string temp1= curr;
            string temp2= curr;
            temp1[k]= ((temp1[k]-'0'+1)%10)+'0';
            if(!st.count(temp1))
            {
                dfs(temp1,tar,st,vis,cnt+1,ans);
            }
            temp2[k]= ((temp2[k]-'0'-1+10)%10)+'0';
            if(!st.count(temp2))
            {
                dfs(temp2,tar,st,vis,cnt+1,ans);
            }
        }
        vis.erase(curr);//backtracking..
    }
    int openLock(vector<string>& deadends, string tar) 
    {
        int n= tar.size();
        unordered_set<string>st(begin(deadends),end(deadends));
        unordered_set<string>vis;

        if(st.count("0000"))
        {
            return -1;
        }
        int ans=INT_MAX;
        string curr="0000";
        dfs(curr,tar,st,vis,0,ans);
        return ans==INT_MAX ? -1:ans; 
    }
*/