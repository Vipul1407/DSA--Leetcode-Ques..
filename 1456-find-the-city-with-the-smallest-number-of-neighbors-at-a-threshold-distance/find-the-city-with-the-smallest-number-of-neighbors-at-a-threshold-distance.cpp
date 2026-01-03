class Solution {
public:
    //FLOYD WARSHAL'S ALGO..
    int findTheCity(int n, vector<vector<int>>& edges, int threshold)
    {
        
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(auto i:edges)
        {
            int u= i[0];
            int v= i[1];
            int w= i[2];
            dist[u][v]= w;
            dist[v][u]= w;
        }
        for(int i=0;i<n;i++)
        {
            dist[i][i]=0;
        }

        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i!=j && dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX)
                    {
                        dist[i][j]= min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }

        /*
            //to detect -ve cycle check if dist[i][j]<0 means there exist a -ve cycle..
        */
        int ans= n+1;
        int city=0;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && dist[i][j]<=threshold)
                {
                    cnt++;
                }
            }
            if(cnt<=ans)
            {
                city= i;
                ans= cnt;
            }
        }
        return city;
    }
};