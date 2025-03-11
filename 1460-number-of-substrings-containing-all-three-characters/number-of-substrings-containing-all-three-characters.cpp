class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int a=0;
        int b=0;
        int c=0;
        int n= s.size();
        int i=0,j=0;
        int ans=0;
        while(j<n)
        {
            if(s[j]=='a')
            {
                a++;
            }
            else if(s[j]=='b')
            {
                b++;
            }
            else
            {
                c++;
            }
            while(a>0 && b>0 && c>0)
            {
                ans+= n-j;
                if(s[i]=='a')
                {
                    a--;
                }
                else if(s[i]=='b')
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
};