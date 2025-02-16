class Solution {
public:
    bool check(int i,int sum,int num,string str,vector<vector<int>>&dp)
    {
        if(i==str.size())
        {
            return sum==num;
        }
        if(sum>num)
        {
            return false;
        }
        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
        bool possi= false;
        for(int j=i;j<str.size();j++)
        {
            string sub= str.substr(i,j-i+1);
            possi= possi || check(j+1,sum+stoi(sub),num,str,dp);
            if(possi==true)
            {
                return true;
            }
        }
        return dp[i][sum]= possi;
    }
    int punishmentNumber(int n) 
    {
        int ans=0;
        for(int num=1;num<=n;num++)
        {
            string str= to_string(num*num);
            vector<vector<int>>dp(str.size()+1,vector<int>(num+1,-1));
            if(check(0,0,num,str,dp))
            {
                ans+= stoi(str);
            }
        }
        return ans;
    }
};