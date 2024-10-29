class Solution {
public:
    bool isunique(string curr)
    {
        vector<int>unique(26,0);
        for(auto j:curr)
        {
            if(unique[j-'a']>0)
            {
                return false;
            }
            unique[j-'a']++;
        }
        return true;
    }
    void solve(int i,string curr,vector<string>& arr,int &maxcnt)
    {
        if(!isunique(curr))
        {
           return;
        }
        maxcnt= max((int)curr.size(),maxcnt);
        
        for(int j=i;j<arr.size();j++)
        {
            solve(j+1,curr+arr[j],arr,maxcnt);
        }
    }
    int maxLength(vector<string>& arr) 
    {
        int maxcnt=0;
        solve(0,"",arr,maxcnt);
        return maxcnt;
    }
};