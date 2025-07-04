class Solution {
public:
    //METHOD-1
    //MY SIMPLE RECUSIVE METHOD..
    //TLE... 
    char kthCharacter(long long k, vector<int>& operations) 
    {
        int n= operations.size();
        long long len=1;
        long long newk= -1;
        int type= -1;
        if(k==1)
        {
            return 'a';
        }
        for(int i=0;i<n;i++)
        {
            len*=2;
            if(len>=k)
            {
                type= operations[i];
                newk= k-len/2;
                break;
            }
        }
        char ch= kthCharacter(newk,operations);
        if(type==0)
        {
            return ch;
        }
        return ch=='z'? 'a':ch+1;
    }
};
/*
        //METHOD-1
    //MY SIMPLE RECUSIVE METHOD..
    //TLE... 
    void solve(int i,string &curr, vector<int>& operations ,long long k)
    {
        if(curr.size()>=k || i>=operations.size())
        {
            return;
        }
        if(operations[i]==0)
        {
            string temp= curr;
            curr+= temp;
            solve(i+1,curr,operations,k);
        }
        else
        {
            string temp;
            for(auto i:curr)
            {
                temp+= (i+1-'a')%26 +'a';
            }
            curr+= temp;
            solve(i+1,curr,operations,k);
        }
    }
    char kthCharacter(long long k, vector<int>& operations) 
    {
        string curr= "a";
        solve(0,curr,operations,k);  
        return curr[k-1];
    }
*/