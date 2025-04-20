class Solution {
public:
    //TC= O(E LOG V)= O(M*N*4 LOG(M*N))
    int minimumEffortPath(vector<vector<int>>& arr) 
    {
        int m= arr.size();
        int n= arr[0].size();
        vector<vector<int>>dis(m,vector<int>(n,1e9));
        //min heap.. diff,row,col
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        dis[0][0]=0;
        vector<int>dx= {-1,0,1,0};
        vector<int>dy= {0,1,0,-1};
        while(pq.size())
        {
            auto top= pq.top();
            pq.pop();
            int d= top.first;
            int r= top.second.first;
            int c= top.second.second;
            if(r==m-1 && c==n-1)
            {
                return d;
            }
            for(int i=0;i<4;i++)
            {
                int newr= r+dx[i];
                int newc= c+dy[i];
                if(newr>=0 && newr<m && newc>=0 && newc<n)
                {
                    int diff= max(d,abs(arr[r][c]-arr[newr][newc]));
                    if(diff<dis[newr][newc])
                    {
                        dis[newr][newc]= diff;
                        pq.push({diff,{newr,newc}});
                    }
                }
            }
        }
        return 0;
    }
};