const int N=100000;
unsigned dist1[N], dist2[N];
class Solution {
public:
    static void dfs(int i, int d, vector<int>& edges, unsigned* dist){
        dist[i]=d;
        int j=edges[i];
        if (j!=-1 && dist[j]==UINT_MAX) dfs(j, d+1, edges, dist); 
    }
    static int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        const int n=edges.size();

        memset(dist1, -1, n*4);
        memset(dist2, -1, n*4);
        dfs(node1, 0, edges, dist1);
        dfs(node2, 0, edges, dist2);
        unsigned minD=UINT_MAX;
        int index=-1;
        for (int i=0; i<n; i++) {
            int max12=max(dist1[i], dist2[i]);
            if (max12<minD ) {
                minD=max12;
                index=i;
            }
        }
        return index;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();