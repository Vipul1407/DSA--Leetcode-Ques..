class Solution {
public:
    //Area= 0.5* ∣(x2​−x1​)(y3​−y1​)−(y2​−y1​)(x3​−x1​)∣
    double largestTriangleArea(vector<vector<int>>& points) 
    {
        double ans=0;
        int n= points.size();
        for(int i=0;i<=n-3;i++)
        {
            int x= points[i][0];
            int y= points[i][1];
            for(int j=i+1;j<=n-2;j++)
            {
                for(int k=j+1;k<=n-1;k++)
                {
                    double area= 0.5*abs((points[j][0]-x)*(points[k][1]-y) - (points[j][1]-y)*(points[k][0]-x));
                    ans= max(ans,area);
                }
            }
        }
        return ans;
    }
};