class Solution {
public:
    //METHOD-2
    //OPTIMIZED..
    int minimumOperations(vector<int>& nums) 
    {
        int n= nums.size();
        unordered_set<int>st;
        for(int i=n-1;i>=0;i--)
        {
            if(st.find(nums[i])!=st.end())
            {
                //we have to remove all elements till i=0 
                return (i/3)+1;
            }
            st.insert(nums[i]);
        }
        return 0;
    }
};
/*
// METHOD-1
// BRUTE FORCE..
bool isunique(vector<int> &nums, int i)
{
    int n = nums.size();
    unordered_set<int> st;
    for (int j = i; j < n; j++)
    {
        if (st.count(nums[j]))
        {
            return false;
        }
        st.insert(nums[j]);
    }
    return true;
}
int minimumOperations(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;

    for (int i = 0; i < n; i += 3)
    {
        if (isunique(nums, i))
        {
            return cnt;
        }
        cnt++;
    }
    return cnt;
}
*/