class Solution {
public:
    //METHOD-2
    //USING FLOYD WARSHALL
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
        // to store prerequisite for each node..
        vector<vector<int>>pre(n,vector<int>(n,0));
        for (auto i : prerequisites)
        {
            pre[i[0]][i[1]]=1;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(pre[i][k]==1 && pre[k][j]==1)
                    {
                        pre[i][j]=1;
                    }
                }
            }
        }
        vector<bool>ans;
        for(auto i:queries)
        {
            int u= i[0];
            int v= i[1];
            if(pre[u][v]==1)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};
/*
// METHOD-1
// USING TOPO SORT (BFS.. KAHN ALGO..)
vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisite, vector<vector<int>> &queries)
{
    unordered_map<int, vector<int>> adj;
    vector<int> indegree(n, 0);
    queue<int> q;
    // to store prerequisite for each node..
    vector<unordered_set<int>> pre(n);
    for (auto i : prerequisite)
    {
        adj[i[0]].push_back(i[1]);
        indegree[i[1]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        auto i = q.front();
        q.pop();
        for (auto &neigh : adj[i])
        {
            // neigh se phle i hoga..
            pre[neigh].insert(i);
            // and jo bhi i ke pre me h vo sare neigh ke  bhi honge as acc. to ques..
            for (auto &j : pre[i])
            {
                pre[neigh].insert(j);
            }
            indegree[neigh]--;
            if (indegree[neigh] == 0)
            {
                q.push(neigh);
            }
        }
    }
    vector<bool> ans;
    for (auto &i : queries)
    {
        if (pre[i[1]].find(i[0]) != pre[i[1]].end())
        {
            ans.push_back(true);
        }
        else
        {
            ans.push_back(false);
        }
    }
    return ans;
}
*/