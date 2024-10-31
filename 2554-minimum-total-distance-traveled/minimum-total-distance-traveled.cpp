class Solution {
public:
    //BUA
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& fact) 
    {
        sort(robot.begin(),robot.end());
        sort(fact.begin(),fact.end());
        vector<int>position;
        for(auto i:fact)
        {
            int cnt= i[1];
            while(cnt--)
            {
                position.push_back(i[0]);
            }
        }
        int rs= robot.size();
        int fs= position.size();
        vector<vector<long long>>dp(rs+1,vector<long long>(fs+1,1e15));
        //BASE CASES...
        //all robots assigned..
        // if(r>=robot.size())
        // {
        //     return 0;
        // }
        for(int f=fs;f>=0;f--)
        {
            dp[rs][f]=0;
        }
        //more requests cannot be assigned.. as robots are left but factories are not left==> dp initialized by 1e15
        // if(f>= position.size())
        // {
        //     return (long long)1e15;
        // }
        for(int r=rs-1;r>=0;r--)
        {
            for(int f=fs-1;f>=0;f--)
            {
                long long inc= abs(robot[r]-position[f])+dp[r+1][f+1];
                long long notinc= dp[r][f+1];
                dp[r][f]= min(inc,notinc);
            }
        }
        return dp[0][0];
    }
};


//TDA...
//BEATS 20%
    /*
    long long rec(int r,int f,vector<int>& robot, vector<int>&position, vector<vector<long long>>&dp)
    {
        //all robots assigned..
        if(r>=robot.size())
        {
            return 0;
        }
        //more requests cannot be assigned.. as robots are left but factories are not left
        if(f>= position.size())
        {
            return (long long)1e15;
        }
        if(dp[r][f]!=-1)
        {
            return dp[r][f];
        }
        long long inc= abs(robot[r]-position[f])+rec(r+1,f+1,robot,position,dp);
        long long notinc= rec(r,f+1,robot,position,dp);
        return dp[r][f]= min(inc,notinc);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& fact) 
    {
        sort(robot.begin(),robot.end());
        sort(fact.begin(),fact.end());
        vector<int>position;
        for(auto i:fact) 
        {
            int cnt= i[1];
            int pos= i[0];
            while(cnt--)
            {
                position.push_back(pos);
            }
        }
        vector<vector<long long>>dp(robot.size(),vector<long long>(position.size(),-1));
        //will apllying 0/1 knapsack logic of include/non-include..
        return rec(0,0,robot,position,dp); 
    }
    */