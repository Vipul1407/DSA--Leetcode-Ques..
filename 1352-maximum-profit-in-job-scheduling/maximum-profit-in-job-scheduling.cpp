class Solution {
public:
    //TDA..
    //TC= O(NLOGN + NLOGN)--> If we apply a binary search like this..
    //If we don not apply that,TC= O(N^2 + NLOGN) 
    int findnextidx(int i,int ending,vector<vector<int>>&vec)
    {
        int l=i;
        int r= vec.size()-1;
        while(l<=r)
        {
            int mid= l+(r-l)/2;
            if(vec[mid][0]>=ending)
            {
                r= mid-1;
            }
            else
            {
                l= mid+1;
            }
        }
        return l;
    }
    int tda(int i, vector<vector<int>>&vec, vector<int>&dp)
    {
        if(i>= vec.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        //passing here the end time..
        int next= findnextidx(i+1,vec[i][1],vec);
        int take= vec[i][2]+ tda(next,vec,dp);
        int notake= tda(i+1,vec,dp);
        return dp[i]= max(take,notake);
    }
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) 
    {
        int n = profit.size();
        vector<int>dp(n,-1);
        vector<vector<int>> vec(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++)
        {
            vec[i][0] = start[i];
            vec[i][1] = end[i];
            vec[i][2] = profit[i];
        }
        sort(vec.begin(), vec.end());
        return tda(0,vec,dp);
    }
};
/*
    // METHOD-1
    // RECURSIVE..
    int getnextidx(int i, int ending, vector<vector<int>> &vec)
    {
        int l = i;
        int r = vec.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (vec[mid][0] >= ending)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
    int rec(int i, vector<vector<int>> &vec)
    {
        if (i >= vec.size())
        {
            return 0;
        }
        int next = getnextidx(i + 1, vec[i][1], vec);
        int take = vec[i][2] + rec(next, vec);
        int notake = rec(i + 1, vec);
        return max(take, notake);
    }
    int jobScheduling(vector<int> &start, vector<int> &end, vector<int> &profit)
    {
        int n = profit.size();
        vector<vector<int>> vec(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++)
        {
            vec[i][0] = start[i];
            vec[i][1] = end[i];
            vec[i][2] = profit[i];
        }
        sort(vec.begin(), vec.end());
        return rec(0, vec);
    }
*/