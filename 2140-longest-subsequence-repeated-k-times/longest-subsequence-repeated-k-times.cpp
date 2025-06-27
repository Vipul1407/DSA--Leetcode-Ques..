class Solution {
public:
    bool issubseq(string &sub, string &s, int k)
    {
        int i=0,j=0;
        int L= sub.size();
        int n= s.size();
        while(i<n && j<k*L)
        {
            if(s[i]==sub[j%L])
            {
                j++;
            }
            i++;
        }
        return j==k*L;
    }
    void solve(string &curr,string &s,vector<int>&canuse,vector<int>&reqfreq,string &ans,int &k,int maxlen)
    {
        if(curr.length()>maxlen)
        {
            return;
        }
        if(curr.length()>ans.length() || (curr.length()==ans.length() && curr>ans))
        {
            if(issubseq(curr,s,k))
            {
                ans= curr;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(canuse[i]==false || reqfreq[i]==0)
            {
                continue;
            }
            char ch= i+'a';
            curr.push_back(ch);
            reqfreq[i]--;

            //explore..
            solve(curr,s,canuse,reqfreq,ans,k,maxlen);

            //undo...
            curr.pop_back();
            reqfreq[i]++;
        }

    }
    string longestSubsequenceRepeatedK(string s, int k)
    {
        int n= s.size();
        vector<int>canuse(26,0);
        vector<int>freq(26,0);
        vector<int>reqfreq(26,0);
        
        for(auto i:s)
        {
            freq[i-'a']++;
            if(freq[i-'a']>=k)
            {
                canuse[i-'a']=1;
                reqfreq[i-'a']= freq[i-'a']/k;
            }
        }
        int maxlen= n/k;
        string ans,curr;
        solve(curr,s,canuse,reqfreq,ans,k,maxlen);
        return ans;
    }
};