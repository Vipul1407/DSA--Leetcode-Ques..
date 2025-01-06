class Solution {
public:
    // METHOD-3
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        vector<int> leftpref(n, 0);
        vector<int> rightpref(n, 0);
        vector<int> ans(n, 0);
        // forming left prefix array...
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += boxes[i] - '0';
            leftpref[i] = sum;
        }
        // forming right prefix array...
        sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            sum += boxes[i] - '0';
            rightpref[i] = sum;
        }
        // we need ans[i]= sum of leftpref from 0 to i-1 + sum of rightpref from i+1 to n
        // here finding sum of leftpref upto i-1
        sum = 0;
        for (int i = 1; i < n; i++)
        {
            sum += leftpref[i - 1];
            ans[i] += sum;
        }
        // here finding sum of rightpref upto i+1
        sum = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            sum += rightpref[i + 1];
            ans[i] += sum;
        }
        return ans;
    }
};