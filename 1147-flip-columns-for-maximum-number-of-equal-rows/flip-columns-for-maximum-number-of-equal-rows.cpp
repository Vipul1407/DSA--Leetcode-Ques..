class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) 
    {
        unordered_map<string,int>mp;
        for(auto i:matrix)
        {
            string normal="";
            string invert="";
            for(auto j:i)
            {
                if(j==0)
                {
                    normal+= "z";
                    invert+= "o"; 
                }
                else
                {
                    normal+= "o";
                    invert+= "z";
                }
            }
            mp[normal]++;
            mp[invert]++;
        }
        //max(same row, inverted row)
        int ans=0;
        for(auto i:mp)
        {
            ans= max(ans,i.second);
        }
        return ans;
    }
};