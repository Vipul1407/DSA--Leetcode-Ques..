//MERRY CHRISTMAS!! 25-DEC-2024 ~Vipul
class Solution {
public:
    //METHOD-2
    //DFS (RECURSION...)
    int ans=0;
    long long dfs(int node,unordered_map<int,vector<int>>&mp,vector<int>&values,vector<int>&vis,int k)
    {
        vis[node]= 1;
        long long sum= values[node];
        for(auto i:mp[node])
        {
            if(vis[i]==1)
            {
                continue;
            }
            sum+= dfs(i,mp,values,vis,k);
            sum%=k;//to avoid out of range for integer..
        }
        if(sum%k==0)
        {
            ans++;
            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) 
    {
        if(n==1)
        {
            return (values[0]%k==0)? 1:0;
        }
        unordered_map<int,vector<int>>mp;
        vector<int>vis(n,0);
        for(auto i:edges)
        {
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        //assuming start node is 0
        dfs(0,mp,values,vis,k);
        return ans;
    }
};
/*
//METHOD-1
//BFS (QUEUE...)
int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) 
    {
        //base case when edges=[]
        if(n==1)
        {
            return (values[0]%k==0)? 1:0;
        }
        unordered_map<int,vector<int>>mp;
        vector<int>indegree(n,0);
        for(auto i:edges)
        {
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
            indegree[i[0]]++;
            indegree[i[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            //pushing only leaf nodes..
            if(indegree[i]==1)
            {
                q.push(i);
            }
        }
        int cnt=0;
        while(q.size())
        {
            int temp= q.front();
            q.pop();
            indegree[temp]--;
            long long toadd= (values[temp]%k==0) ? 0:values[temp]%k; //to avoid integer overflow we will do values[temp]%k
            if(values[temp]%k==0)
            {
                cnt++;
            }
            for(auto i:mp[temp])
            {
                if(indegree[i]>0)
                {
                    indegree[i]--;
                    values[i]+= toadd;
                    if(indegree[i]==1)
                    {
                        q.push(i);
                    }
                }
            }
        }
        return cnt;
    }
*/