class Solution {
public:
    bool issubseq(string &curr, string &s, int &k)
    {
        int i=0,j=0;
        int n= s.size();
        int L= curr.size();
        for(int i=0;i<n && j<k*L;i++)
        {
            if(s[i]==curr[j%L])
            {
                j++;
            }
        }
        return j==k*L;
    }
    bool solve(string &curr, string &s, vector<int>reqfreqtemp, vector<int>canuse, string &ans, int &k, int len)
    {
        if(curr.length()==len)
        {
            if(issubseq(curr,s,k))
            {
                ans= curr;
                return true;
            }
            return false;
        }
        for(int i=25;i>=0;i--)
        {
            if(canuse[i]==0 || reqfreqtemp[i]==0)
            {
                continue;
            }
            char ch= i+'a';
            curr.push_back(ch);
            reqfreqtemp[i]--;

            //explore..
            if(solve(curr,s,reqfreqtemp,canuse,ans,k,len))
            {
                return true;
            }
            //undo...
            curr.pop_back();
            reqfreqtemp[i]++;
        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) 
    {
        int n= s.size();
        vector<int>freq(26,0);
        vector<int>reqfreq(26,0);
        vector<int>canuse(26,0);

        int maxlen= n/k;
        for(auto i:s)
        {
            freq[i-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(freq[i]>=k)
            {
                canuse[i]=1;
                reqfreq[i]= freq[i]/k;
            }
        }
        string ans;
        for(int len= maxlen; len>0; len--)
        {
            string curr="";
            vector<int>reqfreqtemp= reqfreq;
            if(solve(curr,s,reqfreqtemp,canuse,ans,k,len))
            {
                return ans;
            }
        }
        return ans;
    }
};