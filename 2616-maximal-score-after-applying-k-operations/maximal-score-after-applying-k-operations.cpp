class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        priority_queue<long long> maxheap;
        for(auto i : nums) maxheap.push(i);

        long long score = 0;

        for(int i = 0; i < k; i++) {
            int n = maxheap.top();
            score += n;
            maxheap.pop();
            n = ceil((double) n/3);
            maxheap.push(n);
        }
        return score;
    }
};