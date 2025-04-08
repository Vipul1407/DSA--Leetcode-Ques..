class Solution {
public:
    bool isunique(vector<int>& nums, int i)
    {
        int n= nums.size();
        unordered_set<int>st;
        for(int j=i;j<n;j++)
        {
            if(st.count(nums[j]))
            {
                return false;
            }
            st.insert(nums[j]);
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) 
    {
        int n= nums.size();
        int cnt=0;
        
        for(int i=0;i<n;i+=3)
        {
            if(isunique(nums,i))
            {
                return cnt;
            }
            cnt++;
        }
        return cnt;
    }
};