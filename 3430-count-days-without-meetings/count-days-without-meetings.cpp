class Solution 
{
public:

    int countDays(int days, vector<vector<int>>& meet) 
    {
        int n=meet.size();
        //first merge intervals
        sort(meet.begin(),meet.end());
        int cnt=0;
        int start=meet[0][0];
        int end=meet[0][1];
        //start from i=1
        for(int i=1;i<n;i++)
        {
            if(meet[i][0]>end)
            {
               cnt+=end-start+1;
               start=meet[i][0];
               end=meet[i][1];
            }
            else
            {
                end=max(end,meet[i][1]);
            }
        }
        //adding last interval
        cnt+=end-start+1;
        return days-cnt;
    }
};