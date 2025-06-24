class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
    {
        int n= nums.size();
        vector<int>vec,ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==key)
            {
                vec.push_back(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(auto j:vec)
            {
                if(abs(i-j)<=k)
                {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};