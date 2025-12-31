constexpr int N=2e4+2;// plus East & West cells
using u16=unsigned short;
u16 Rt[N], Rk[N];
class UnionFind{
    u16 n, *root, *rank;
public:
    UnionFind(int n):n(n){
        root=Rt;
        rank=Rk;
        iota(root, root+n, 0);
        fill(rank, rank+n, 1);
    }
    int Find(int x) {
        return (x == root[x])?x: root[x]=Find(root[x]);
    }
    void Union(int x, int y) {
        int rX = Find(x), rY = Find(y);
        if (rX == rY)  return;
        if (rank[rX] > rank[rY]) swap(rX, rY);   
        root[rX] = rY;
        if (rank[rX]==rank[rY]) rank[rY]++;
    }
    bool connected(int x, int y) {
        return Find(x) == Find(y);
    }
};
class Solution {
public:
    using int2=pair<u16, u16>;
    // 1-indexed
    static u16 key(u16 i, u16 j, u16 col){ return (i-1)*col+(j-1); }

    static int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        const int n=cells.size()+2;// add 2 cells East & West 
        UnionFind G(n);
        bitset<N> isWater=0;
        const u16 East=n-2, West=n-1;
        int t=0;
        for(auto& C: cells){
            const u16 i=C[0], j=C[1], idx0=key(i, j, col);// 1-indexed pair
            isWater[idx0]=1;
            if (j==1) G.Union(West, idx0);
            if (j==col) G.Union(East, idx0);

            // waterway must consider 8 directions
            int2 adj[8]={{i+1, j-1}, {i+1, j}, {i+1, j+1}, 
            {i, j+1},{i-1, j+1}, {i-1, j}, {i-1, j-1}, {i, j-1}};

            for (const auto& [a, b] : adj) {
                if (a<=0 || a>row || b<=0 || b>col ) continue;
                u16 idx1=key(a, b, col);
                if (!isWater[idx1]) continue;
                // Waterway is connected for idx0 &idx1
                G.Union(idx0, idx1); 
                if (G.connected(East, West)) return t;
            }
            t++;
        }
        return 0;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();