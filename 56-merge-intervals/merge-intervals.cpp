class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) 
    {
        int n= inter.size();
        sort(inter.begin(),inter.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            int start= inter[i][0];
            int end= inter[i][1];
            if(ans.empty() || ans.back()[1]<start)
            {
                ans.push_back(inter[i]);
            }
            else
            {
                ans.back()[1]= max(ans.back()[1],end);
            }
        }
        return ans;
    }
};