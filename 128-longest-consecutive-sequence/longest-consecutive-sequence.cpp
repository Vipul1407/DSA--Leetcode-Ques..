class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size()==0)
        {
            return 0;
        }
        unordered_set<int>st(nums.begin(),nums.end());
        int ans=1;
        //will run on set not on nums array..
        for(auto i:st)
        {
            int cnt=1;
            int ele=i;
            //if i-1 element ni mila mtlb this ight be the starting point of sequence..
            if(st.find(ele-1)==st.end())
            {
                while(st.find(ele+1)!=st.end())
                {
                    cnt++;
                    ele++;
                }
                ans= max(ans,cnt);
            }
        }
        return ans;
    }
};