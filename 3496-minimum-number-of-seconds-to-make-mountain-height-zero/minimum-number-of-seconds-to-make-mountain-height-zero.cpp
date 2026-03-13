using ll = long long;
class Solution {
public:
    ll minNumberOfSeconds(int height, vector<int>& times) {
        ll lo = 1, hi = 1e16;
        ll res = hi;

        while (lo <= hi) {
            ll mid = lo + ((hi - lo) >> 1);
            ll sum = 0;

            for (int i = 0; i < times.size() && sum < height; i++)
                sum += (ll)(sqrt((double)mid / times[i] * 2 + 0.25) - 0.5);

            if (sum >= height) {
                res = mid;
                hi = mid - 1;
            } else
                lo = mid + 1;
        }

        return res;
    }
};