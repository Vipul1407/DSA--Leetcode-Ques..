class Solution {
public:
    //METHOD-2
    //ITERATIVE..
    char kthCharacter(int k) 
    {
        string ans="a";
        while(ans.size()<k)
        {
            string temp;
            for(auto i:ans)
            {
                temp+= (i+1-'a')%26 + 'a';
            }
            ans+= temp;
        }
        return ans[k-1];
    }
};
/*
    //METHOD-1
    //RECURSIVE..
    //TC= O(1+2+4+8+..2^N)= O(2^N -1)= O(K)
    //SC= O(LOG2(N)+K)= O(K)
    void solve(int k,string str,string &ans)
    {
        if(str.size()>=k)
        {
            ans= str;
            return;
        }
        string temp;
        for(auto i:str)
        {
            int ascii= i-'a';
            temp+= (ascii+1)%26 + 'a';
        }
    
        solve(k,str+temp,ans);
    }
    char kthCharacter(int k) 
    {
        string ans="";
        solve(k,"a",ans);
        return ans[k-1];//since k is 1 based
    }
*/