class Solution {
public:

    //METHOD-2
    //USING DFS...
    int solve(int node, int parent,unordered_map<int,vector<int>>&mp, int &dia)
    {
        int ht=0;
        for(int neigh:mp[node])
        {
            if(neigh==parent)
            {
                continue;
            }
            int subtreeht= solve(neigh,node,mp,dia);
            dia= max(dia, ht+subtreeht+1);
            //1 will be added in subtreeht not after max() becoz
            ht= max(ht,subtreeht+1);
        }
        return ht;
    }
    int find_diameter(unordered_map<int,vector<int>>&mp)
    {
        int dia=0;
        //starting node is 0 and parent is -1
        solve(0,-1,mp,dia);
        return dia;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) 
    {
        unordered_map<int,vector<int>>mp1;
        unordered_map<int,vector<int>>mp2;
        for(auto i:edges1)
        {
            mp1[i[0]].push_back(i[1]);
            mp1[i[1]].push_back(i[0]);
        }
        for(auto i:edges2)
        {
            mp2[i[0]].push_back(i[1]);
            mp2[i[1]].push_back(i[0]);
        }
        int d1= find_diameter(mp1);
        int d2= find_diameter(mp2);
        int combined= (d1+1)/2 + (d2+1)/2 + 1;
        return max(d1,max(d2,combined));
    }
};
/*
// METHOD-1
// BFS (USING QUEUE)...
pair<int, int> bfs(unordered_map<int, vector<int>> &mp, int src)
{
    queue<int> q;
    unordered_set<int> vis;
    q.push(src);
    vis.insert(src);
    int temp = src;
    int d = 0; // this will track the level assumiung we are at 0th level as we have to cnt edges not nodes in diameter..
    while (q.size())
    {
        int size = q.size(); // to reaverse level by level..
        while (size--)
        {
            temp = q.front();
            q.pop();
            for (auto i : mp[temp])
            {
                if (vis.find(i) == vis.end())
                {
                    q.push(i);
                    vis.insert(i);
                }
            }
        }
        if (q.size())
        {
            d++;
        }
    }
    return {temp, d};
}
int find_distance(unordered_map<int, vector<int>> &mp)
{
    // find one end assuming starting form 0th node..
    auto [end, d] = bfs(mp, 0);
    // find other end assuming starting from above find one end node..
    auto [otherend, diameter] = bfs(mp, end);
    return diameter;
}
int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
{
    unordered_map<int, vector<int>> mp1;
    unordered_map<int, vector<int>> mp2;
    for (auto i : edges1)
    {
        mp1[i[0]].push_back(i[1]);
        mp1[i[1]].push_back(i[0]);
    }
    for (auto i : edges2)
    {
        mp2[i[0]].push_back(i[1]);
        mp2[i[1]].push_back(i[0]);
    }
    int d1 = find_distance(mp1);
    int d2 = find_distance(mp2);
    int combined = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;
    return max(d1, max(d2, combined));
}
*/