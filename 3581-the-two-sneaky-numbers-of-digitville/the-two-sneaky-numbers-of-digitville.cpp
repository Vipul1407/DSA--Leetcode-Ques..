class Solution {
public:
    //SC= O(N)
    vector<int> getSneakyNumbers(vector<int>& nums) 
    {
        vector<int>freq(101,0);
        vector<int>ans;
        for(auto i:nums)
        {
            freq[i]++;
            if(freq[i]==2)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};