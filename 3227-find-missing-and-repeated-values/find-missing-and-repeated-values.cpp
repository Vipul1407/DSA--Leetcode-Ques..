class Solution {
public:
    //METHOD-2
    //USING VECTOR..
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        int n= grid.size();
        int x=-1, y=-1;
        vector<int>vec(n*n+1,0);
        for(auto i:grid)
        {
            for(auto j:i)
            {
                vec[j]++;
            }
        }
        for(int i=0;i<=n*n;i++)
        {
            if(vec[i]==0)
            {
                y= i;
            }
            if(vec[i]==2)
            {
                x= i;
            }
        }
        return {x,y};
    }
};

/*
    //METHOD-1
    //USING UNORDERED MAP..
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        int n= grid.size();
        int x=-1,y=-1;
        unordered_map<int,int>vec;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                vec[grid[i][j]]++;
            }
        }
        for(int k=1;k<=n*n;k++)
        {
            int val= vec[k];
            if(val==2)
            {
                x= k;
            }
            if(val==0)
            {
                y= k;
            }
        }
        return {x,y};
    }
*/
