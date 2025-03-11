class Solution {
public:
    //METHOD-2
    //Using Vector..
    int numberOfSubstrings(string s) 
    {
        int n= s.size();
        vector<int>cnt(3,0);
        int ans=0,i=0,j=0;
        while(j<n)
        {
            cnt[s[j]-'a']++;
            while(cnt[0]>0 && cnt[1]>0 && cnt[2]>0)
            {
                ans+= n-j;
                cnt[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
/*
//METHOD-1
//Using Variables..
int numberOfSubstrings(string s)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int n = s.size();
    int i = 0, j = 0;
    int ans = 0;
    while (j < n)
    {
        if (s[j] == 'a')
        {
            a++;
        }
        else if (s[j] == 'b')
        {
            b++;
        }
        else
        {
            c++;
        }
        while (a > 0 && b > 0 && c > 0)
        {
            ans += n - j;
            if (s[i] == 'a')
            {
                a--;
            }
            else if (s[i] == 'b')
            {
                b--;
            }
            else
            {
                c--;
            }
            i++;
        }
        j++;
    }
    return ans;
}
*/