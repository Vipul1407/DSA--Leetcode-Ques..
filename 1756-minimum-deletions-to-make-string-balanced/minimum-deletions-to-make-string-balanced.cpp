class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();

        vector<int> leftB(n, 0);
        leftB[0] = (s[0] == 'b');

        for (int i = 1; i < n; i++) {
            leftB[i] = leftB[i - 1] + (s[i] == 'b');
        }

        vector<int> rightA(n, 0);
        rightA[n - 1] = (s[n - 1] == 'a');

        for (int i = n - 2; i >= 0; i--) {
            rightA[i] = rightA[i + 1] + (s[i] == 'a');
        }

        int ans = min(leftB[n - 1], rightA[0]); // all b’s or all a’s

        for (int j = 1; j < n; j++) {
            ans = min(ans, leftB[j - 1] + rightA[j]);
        }

        return ans;
    }
};
