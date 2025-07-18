class Solution {
public:
    //METHOD-4
    //DSU..
    //TC= O(M+N)
    int findpar(int node, vector<int>&par)
    {
        if(par[node]==node)
        {
            return node;
        }
        return par[node]= findpar(par[node],par);
    }
    void unionbyrank(int u,int v, vector<int>&par)
    {
        int pu= findpar(u,par);
        int pv= findpar(v,par);
        if(pu==pv)
        {
            return;
        }
        //no need of rank...
        //make always smaller as parent
        if(pu<pv)
        {
            par[pv]= pu;
        }
        else
        {
            par[pu]= pv;
        }
    }
    string smallestEquivalentString(string s1, string s2, string base) 
    {
        int n= s1.size();
        vector<int>par(26);
        for(int i=0;i<26;i++)
        {
            par[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            unionbyrank(s1[i]-'a',s2[i]-'a',par);
        }
        string ans="";
        for(int i=0;i<base.size();i++)
        {
            ans+= findpar(base[i]-'a',par)+'a';
        }
        return ans;
    }
};
/*
    // METHOD-1
    // DFS..   return type is void.
    // TC= O(M* (E+V))
    void dfs(char ch, unordered_map<int, vector<int>> &adj, char &mini, vector<int> &vis)
    {
        if (vis[ch - 'a'] == 1)
        {
            return;
        }
        vis[ch - 'a'] = 1;    // mark as visted;
        mini = min(mini, ch); // update min elment...
        for (auto i : adj[ch])
        {
            if (vis[i - 'a'] == 0)
            {
                dfs(i, adj, mini, vis);
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string base)
    {
        unordered_map<int, vector<int>> adj;
        int n = s1.size();
        for (int i = 0; i < n; i++)
        {
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }
        string ans = "";
        for (auto i : base)
        {
            char mini = i;
            vector<int> vis(26, 0);
            dfs(i, adj, mini, vis);
            ans += mini;
        }
        return ans;
    }

    // METHOD-2
    // DFS..   return typ is char.
    // TC= O(M* (E+V))
    char dfs(char ch, unordered_map<int, vector<int>> &adj, vector<int> &vis)
    {
        vis[ch - 'a'] = 1; // mark as visted;
        char mini = ch;
        for (auto i : adj[ch])
        {
            if (vis[i - 'a'] == 0)
            {
                mini = min(mini, dfs(i, adj, vis));
            }
        }
        return mini;
    }
    string smallestEquivalentString(string s1, string s2, string base)
    {
        unordered_map<int, vector<int>> adj;
        int n = s1.size();
        for (int i = 0; i < n; i++)
        {
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }
        string ans = "";
        for (auto i : base)
        {
            vector<int> vis(26, 0);
            ans += dfs(i, adj, vis);
        }
        return ans;
    }

    //METHOD-3
    //BFS..
    //TC= O(M* (E+V))
    char bfs(char ch, unordered_map<char,vector<char>>&adj)
    {
        char mini= ch;
        queue<char>q;
        q.push(ch);
        vector<int>vis(26,0);
        while(!q.empty())
        {
            auto top= q.front();
            q.pop();
            for(auto i:adj[top])
            {
                if(vis[i-'a']==0)
                {
                    mini= min(mini,i);
                    vis[i-'a']=1;
                    q.push(i);
                }
            }
        }
        return mini;
    }
    string smallestEquivalentString(string s1, string s2, string base) 
    {
        int n= s1.size();
        unordered_map<char,vector<char>>adj;
        for(int i=0;i<n;i++)
        {
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }
        string ans="";
        for(auto i:base)
        {
            ans+= bfs(i,adj);
        }
        return ans;
    }
*/