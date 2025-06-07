class Solution {
public:
    //METHOD-2
    //DFS..   return typ is char.
    //TC= O(M* (E+V))
    char dfs(char ch, unordered_map<int,vector<int>>&adj, vector<int>&vis)
    {
        vis[ch-'a']=1;//mark as visted;
        char mini= ch;
        for(auto i:adj[ch])
        {
            if(vis[i-'a']==0)
            {
                mini= min(mini, dfs(i,adj,vis));
            }
        }
        return mini;
    }
    string smallestEquivalentString(string s1, string s2, string base) 
    {
        unordered_map<int,vector<int>>adj;
        int n= s1.size();
        for(int i=0;i<n;i++)
        {
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }
        string ans="";
        for(auto i:base)
        {
            vector<int>vis(26,0);
            ans+= dfs(i,adj,vis);
        }
        return ans;
    }
};
/*
    //METHOD-1
    //DFS..   return type is void.
    //TC= O(M* (E+V))
    void dfs(char ch, unordered_map<int,vector<int>>&adj, char &mini, vector<int>&vis)
    {
        if(vis[ch-'a']==1)
        {
            return;
        }
        vis[ch-'a']=1;//mark as visted;
        mini= min(mini,ch);//update min elment...
        for(auto i:adj[ch])
        {
            if(vis[i-'a']==0)
            {
                dfs(i,adj,mini,vis);
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string base) 
    {
        unordered_map<int,vector<int>>adj;
        int n= s1.size();
        for(int i=0;i<n;i++)
        {
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }
        string ans="";
        for(auto i:base)
        {
            char mini= i;
            vector<int>vis(26,0);
            dfs(i,adj,mini,vis);
            ans+= mini;
        }
        return ans;
    }
*/