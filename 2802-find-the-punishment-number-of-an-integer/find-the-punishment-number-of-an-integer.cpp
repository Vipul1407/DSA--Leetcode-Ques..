class Solution {
public:
    //METHOD-3
    //EASY APPROACH
    bool check(int sq, int sum, int num)
    {
        if(sq==0)
        {
            return sum==num;
        }
        return check(sq/10,sum+sq%10,num) || check(sq/100,sum+sq%100,num) || check(sq/1000,sum+sq%1000,num) || check(sq/10000,sum+sq%10000,num);
    }
    int punishmentNumber(int n) 
    {
        int ans=0;
        for(int num=1;num<=n;num++)
        {
            if(check(num*num,0,num))
            {
                ans+= num*num;
            }
        }
        return ans;
    }
};
/*
// METHOD-1
// RECURSION..
// BEATS 21%
bool check(int i, int sum, int num, string str)
{
    if (i == str.size())
    {
        return sum == num;
    }
    bool possi = false;
    for (int j = i; j < str.size(); j++)
    {
        string sub = str.substr(i, j - i + 1);
        possi = possi || check(j + 1, sum + stoi(sub), num, str);
        if (possi == true)
        {
            return true;
        }
    }
    return false;
}
int punishmentNumber(int n)
{
    int ans = 0;
    for (int num = 1; num <= n; num++)
    {
        int str = num * num;
        if (check(0, 0, num, to_string(str)))
        {
            ans += str;
        }
    }
    return ans;
}

// METHOD-2
// TDA MEMOIZATION..
// TC= O(N*2^LOG10(N*N))
// SC= O(N*LOG10(N*N) + N)
bool check(int i, int sum, int num, string str, vector<vector<int>> &dp)
{
    if (i == str.size())
    {
        return sum == num;
    }
    if (sum > num)
    {
        return false;
    }
    if (dp[i][sum] != -1)
    {
        return dp[i][sum];
    }
    bool possi = false;
    for (int j = i; j < str.size(); j++)
    {
        string sub = str.substr(i, j - i + 1);
        possi = possi || check(j + 1, sum + stoi(sub), num, str, dp);
        if (possi)
        {
            return dp[i][sum] = possi;
        }
    }
    return dp[i][sum] = possi;
}
int punishmentNumber(int n)
{
    int ans = 0;
    for (int num = 1; num <= n; num++)
    {
        string str = to_string(num * num);
        vector<vector<int>> dp(str.size() + 1, vector<int>(num + 1, -1));
        if (check(0, 0, num, str, dp))
        {
            ans += stoi(str);
        }
    }
    return ans;
}
*/