class Solution {
public:
    //METHOD-2
    //NOT A TOPO SORT DFS..  (It's a Cycle Detection in Directed Graph + Stack)
    bool dfs(int i, unordered_map<int, vector<int>> &adj, vector<int> &vis, vector<int> &pathvis, stack<int>&st)
    {
        vis[i] = 1;
        pathvis[i] = 1;
        for (auto neigh : adj[i])
        {
            // cycle mil gyi..
            if (vis[neigh] && pathvis[neigh])
            {
                return true;
            }
            if (!vis[neigh])
            {
                if (dfs(neigh, adj, vis, pathvis, st))
                {
                    return true;
                }
            }
        }
        // backtracking..
        pathvis[i] = 0;
        st.push(i);
        return false;
    }
    vector<int> findOrder(int course, vector<vector<int>> &pre)
    {
        vector<int> pathvis(course, 0);
        vector<int> vis(course, 0);
        stack<int>st;
        unordered_map<int, vector<int>> adj;
         for (auto i : pre)
        {
            // 0->1
            // then 1 should come before 0..
            adj[i[1]].push_back(i[0]);
        }
        // to handle all disconnected components..
        for (int i = 0; i < course; i++)
        {
            if (!vis[i])
            {
                //agar cylce mil gyi..
                if(dfs(i, adj, vis, pathvis, st))
                {
                    return {};
                }
            }
        }
        if(st.size()!= course)
        {
            return {};
        }
        vector<int>ans;
        while(st.size())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
/*
    // METHOD-1
    // TOPO SORT USING BFS..(KAHN ALGO..) as it ensures cycle detection also..
    vector<int> findOrder(int course, vector<vector<int>> &pre)
    {
        queue<int> q;
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(course, 0);
        vector<int>ans;
        for (auto i : pre)
        {
            // 0->1
            // then 1 should come before 0..
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        for (int i = 0; i < course; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                ans.push_back(i);
            }
        }
        while (q.size())
        {
            auto i = q.front();
            q.pop();
            for (auto &neigh : adj[i])
            {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                {
                    q.push(neigh);
                    ans.push_back(neigh);
                }
            }
        }
        if(ans.size()!=course)
        {
            return {};
        }
        return ans;
    }
*/