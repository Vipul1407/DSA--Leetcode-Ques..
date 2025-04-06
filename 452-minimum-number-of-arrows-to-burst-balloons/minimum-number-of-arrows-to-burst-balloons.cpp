class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        int n= points.size();
        sort(points.begin(),points.end(),[](auto &a, auto &b){
           return a[1]<b[1]; 
        });
        int cnt=1;
        int prevend= points[0][1];
        for(int i=1;i<n;i++)
        {
            int start= points[i][0];
            int end= points[i][1];
            if(start>prevend)
            {
                cnt++;
                prevend= end;
            }
        }
        return cnt;
    }
};