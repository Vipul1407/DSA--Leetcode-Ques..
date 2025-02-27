

class Solution {
public:
    long long maxSubarraySum(vector<int>& v, int k) {
        vector<long long> m(k + 1, 1e18); 
        long long ans = -1e18;
        long long sm = 0;
        int x, y;
        for (int i = 0; i < v.size(); i++) { 
            sm += v[i];
            x = i + 1;
            y = (x % k);
            if (y == 0)
            {
                ans = max(ans, sm);
            }
            ans = max(ans, sm - m[y]);
            m[y] = min(m[y], sm);
        }
        return ans;
    }
};