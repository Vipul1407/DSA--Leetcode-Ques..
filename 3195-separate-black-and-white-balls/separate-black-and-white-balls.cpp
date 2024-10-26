class Solution {
public:
    long long minimumSteps(string s) 
    {
        //left-->right
        long long ans=0;
        int cnt1=0;
        for(auto i:s)
        {
            if(i=='1')
            {
                cnt1++;
            }
            else
            {
                ans+=cnt1;
            }
        }
        return ans;
    }
};