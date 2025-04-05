class Solution {
public:
    // METHOD-3
    // OBSERVATION BASED..
    int subsetXORSum(vector<int> &nums)
    {
        int orv = 0;
        for (auto i : nums)
        {
            orv |= i;
        }
        // convert or into binary then
        // append size-1 '0' in last
        int sum = 0;
        int n = nums.size();
        ;
        return orv << n - 1;
    }
};
/*
// METHOD-1
// GENERATE SUBSETS THEN TAKE THE SUM OF ALL
void generate(int i, vector<int> &nums, vector<int> vec, vector<vector<int>> &ans)
{
    if (i >= nums.size())
    {
        ans.push_back(vec);
        return;
    }
    // include..
    vec.push_back(nums[i]);
    generate(i + 1, nums, vec, ans);
    // not include..
    vec.pop_back();
    generate(i + 1, nums, vec, ans);
}
int subsetXORSum(vector<int> &nums)
{
    vector<int> vec;
    vector<vector<int>> ans;
    generate(0, nums, vec, ans);
    int sum = 0;
    for (auto i : ans)
    {
        int xorv = 0;
        for (auto j : i)
        {
            xorv ^= j;
        }
        sum += xorv;
    }
    return sum;
}

// METHOD-2
// TAKE XOR SUM DIRECTLY.. RETURN TYPE IS INT
int solve(int i, vector<int> &nums, int xorv)
{
    if (i >= nums.size())
    {
        return xorv;
    }
    int include_xor = solve(i + 1, nums, xorv ^ nums[i]);
    int notinclude_xor = solve(i + 1, nums, xorv);
    return include_xor + notinclude_xor;
}
int subsetXORSum(vector<int> &nums)
{
    return solve(0, nums, 0);
}

// METHOD-3
// RETURN TYPE IS VOID
void solve(vector<int> &nums, int i, int curr, int &ans)
{
    if (i == nums.size())
    {
        ans += curr;
        return;
    }
    solve(nums, i + 1, curr, ans);
    solve(nums, i + 1, curr ^ nums[i], ans);
}

int subsetXORSum(vector<int> &nums)
{
    int curr = 0, ans = 0;
    solve(nums, 0, curr, ans);
    return ans;
}
*/