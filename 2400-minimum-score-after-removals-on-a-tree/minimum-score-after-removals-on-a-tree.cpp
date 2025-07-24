class Solution {
public:
    int time;
    int dfs(int node, int parent, vector<vector<int>>& adjList, vector<int>& in,
            vector<int>& out, vector<int>& rootXor, vector<int>& nums) {
        in[node] = time++;
        rootXor[node] = nums[node];
        for (int j : adjList[node]) {
            if (j != parent)
                rootXor[node] ^= dfs(j, node, adjList, in, out, rootXor, nums);
        }
        out[node] = time++;
        return rootXor[node];
    }
    int getDiff(int a, int b, int c) {
        return max({a, b, c}) - min({a, b, c});
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> in(n, -1);
        vector<int> out(n, -1);
        vector<int> rootXor(n, 0);
        time = 0;
        vector<vector<int>> adjList(n);
        for (vector<int>& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1, adjList, in, out, rootXor, nums);
        int ans = INT_MAX;
        for (int u = 1; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                int xor_u = rootXor[u];
                int xor_v = rootXor[v];
                int totalXor = rootXor[0];

                if (in[u] < in[v] && in[v] < out[u]) // v is in subtree of u
                    ans =
                        min(ans, getDiff(totalXor ^ xor_u, xor_u ^ xor_v, xor_v));
                else if (in[v] < in[u] && in[u] < out[v]) // u is in subtree of v
                    ans =
                        min(ans, getDiff(totalXor ^ xor_v, xor_u ^ xor_v, xor_u));
                else // Disjoint subtrees
                    ans = min(ans, getDiff(totalXor ^ xor_u ^ xor_v,
                                          xor_u, xor_v));
            }
        }
        return ans;
    }
};