class Solution {
public:
    typedef pair<int,pair<int,int>>p;
    vector<vector<int>>dir= {{-1,0},{0,1},{1,0},{0,-1}};
    int trapRainWater(vector<vector<int>>& arr) 
    {
        int m= arr.size();
        int n= arr[0].size();
        priority_queue<p,vector<p>,greater<p>>pq;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        
        //1st and last row... push in pq
        for(int row=0;row<m;row++)
        {
            for(int col:{0,n-1})
            {
                pq.push({arr[row][col],{row,col}});
                vis[row][col]= true;
            }
        }
        //1st and last col.. push in pq
        for(int col=0;col<n;col++)
        {
            for(int row:{0,m-1})
            {
                pq.push({arr[row][col],{row,col}});
                vis[row][col]= true;
            }
        }

        int water=0;
        while(pq.size())
        {
            int ht= pq.top().first;
            int x= pq.top().second.first;
            int y= pq.top().second.second;
            pq.pop();
            for(vector<int>&d:dir)
            {
                int i= x+d[0];
                int j= y+d[1];
                if(i>=0 && j>=0 && i<m && j<n && !vis[i][j])
                {
                    water+= max(ht-arr[i][j],0);
                    pq.push({max(ht,arr[i][j]),{i,j}});
                    vis[i][j]= true;
                }
            }
        }
        return water;
    }
};
