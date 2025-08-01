class Solution {
public:
    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>>ans;
        vector<int>prev;
        for(int size=1;size<=n;size++)
        {
            vector<int>curr(size,1);
            if(size>=3)
            {
                int i=0;
                int j= size-2;
                int idx=1;
                while(i<j)
                {
                    curr[idx]= prev[i]+prev[i+1];
                    i++;idx++;
                }
            }
            ans.push_back(curr);
            prev= curr;
        }
        return ans;
    }
};