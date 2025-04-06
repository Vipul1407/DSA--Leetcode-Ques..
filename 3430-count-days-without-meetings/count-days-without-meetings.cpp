class Solution {
public:
    int countDays(int days, vector<vector<int>>& meet) 
    {
        int n= meet.size();
        sort(meet.begin(),meet.end());
        int prevend= meet[0][1];
        int ans= meet[0][0]-1;
        for(int i=1;i<n;i++)
        {
            int start= meet[i][0];
            int end= meet[i][1];
            if(start>prevend)
            {
                ans+= start-prevend-1;
                prevend= end;
            }
            else
            {
                prevend= max(prevend,end);
            }
        }
        if(prevend<days)
        {
            ans+= days-prevend;
        }
        return ans;
    }
};