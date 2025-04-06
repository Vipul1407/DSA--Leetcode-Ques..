class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) 
    {
        int n= inter.size();
        sort(inter.begin(),inter.end(),[](auto &a, auto &b){
            return a[1]<b[1];
        });
        int cnt=0;
        int prevend= inter[0][1];
        for(int i=1;i<n;i++)
        {
            int start= inter[i][0];
            int end= inter[i][1];
            //overlap needed..
            if(start<prevend)
            {
                cnt++;
            }
            else
            {
                prevend= end;
            }
        }
        return cnt;
    }
};