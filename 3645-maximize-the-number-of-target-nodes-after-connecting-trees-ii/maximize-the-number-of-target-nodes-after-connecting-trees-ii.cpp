class Solution {

    void dfs(int u, int par, const vector<int> *adj, vector<int> &color, int &cnt0, int &cnt1) {

        if(color[u] == 0) {
            cnt0++;
        } else {
            cnt1++;
        }

        for(auto v: adj[u]) {

            if(par == v) continue;

            color[v] = (color[u] == 0) ? 1 : 0;
            dfs(v, u, adj, color, cnt0, cnt1);
        }

        return;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<int> adj1[n];
        vector<int> adj2[m];

        for(auto &edge: edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }

        for(auto &edge: edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        //Making Bipartite graph;
        int cntA0 = 0;
        int cntA1 = 0;

        int cntB0 = 0;
        int cntB1 = 0;

        vector<int> color1(n, 0);
        vector<int> color2(m, 0);

        dfs(0, -1, adj2, color2, cntB0, cntB1);

        int maxiB = max(cntB0, cntB1);

        dfs(0, -1, adj1, color1, cntA0, cntA1);

        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {

            ans[i] = maxiB;

            if(color1[i] == 0) {
                ans[i] += cntA0;
            } else {
                ans[i] += cntA1;
            }
        }

        return ans;

    }
};