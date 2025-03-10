class Solution {
public:
    bool complete(unordered_map<char,int>&mp, int &conso, int &k)
    {
        if(mp['a']==0 || mp['e']==0 || mp['i']==0 || mp['o']==0 || mp['u']==0)
        {
            return false;
        }
        return conso>=k;
    }
    long long solve(string word, int k)
    {
        int n= word.size();
        int i=0,j=0;
        unordered_map<char,int>mp;
        int conso=0;
        long long ans=0;
        while(j<n)
        {
            if(word[j]=='a' || word[j]=='e' || word[j]=='i' || word[j]=='o' || word[j]=='u')
            {
                mp[word[j]]++;
            }
            else
            {
                conso++;
            }
            while(complete(mp,conso,k))
            {
                ans+= n-j;
                if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u')
                {
                    mp[word[i]]--;
                }
                else
                {
                    conso--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) 
    {
        return solve(word,k)-solve(word,k+1);
    }
};