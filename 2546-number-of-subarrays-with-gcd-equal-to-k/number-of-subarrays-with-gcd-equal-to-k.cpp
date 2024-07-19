class Solution {
public:
    //  BRUTE FORCE
    int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }
    int subarrayGCD(vector<int> &nums, int k)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int curr = 0;               // 0 will not effect our gcd , it we take gcd(1,x)=1 so not take 1
            for (int j = i; j < n; j++) // start loop from i
            {
                curr = gcd(nums[j], curr);
                if (curr == k)
                {
                    ans++;
                }
                else if (curr < k)
                {
                    break;
                }
            }
        }
        return ans;
    }
};