class Solution 
{
public:
    static bool cmp(const vector<int>&a, const vector<int>&b)
    {
        //sort by start time..
        if(a[0]!=b[0])
        {
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    int binarys(vector<vector<int>>&events, int end)
    {
        int l=0;
        int r=events.size()-1;
        int start=-1;
        while(l<=r)
        {
            int mid= l+(r-l)/2;
            if(events[mid][0]>end)
            {
                start= mid;
                r= mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return start==-1? events.size():start;
    }
    int solve(vector<vector<int>>& events, int i, int cnt, vector<vector<int>>&dp)
    {
        if(cnt==2 || i>=events.size())
        {
            return 0;
        }
        if(dp[i][cnt]!=-1)
        {
            return dp[i][cnt];
        }
        int ubi= binarys(events,events[i][1]);
        int take= events[i][2]+ solve(events,ubi,cnt+1,dp);
        int notake= solve(events,i+1,cnt,dp);
        return dp[i][cnt]= max(take,notake);
    }
    int maxTwoEvents(vector<vector<int>>& events) 
    {
        int n= events.size();
        sort(events.begin(),events.end(),cmp);
        int cnt=0;
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(events,0,cnt,dp);
    }
};