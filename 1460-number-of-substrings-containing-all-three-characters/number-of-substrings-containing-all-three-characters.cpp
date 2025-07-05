class Solution {
public:
    //METHOD-2
    //SIMPLE APPROACH
    int numberOfSubstrings(string s) 
    {
        int n= s.size();
        //recent index..
        int a=-1,b=-1,c=-1,ans=0;
 
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                a=i;
            }
            else if(s[i]=='b')
            {
                b=i;
            }
            else
            {
                c=i;
            }
            ans+= 1+min(a,min(b,c));
        }   
        return ans;
    }
};
/*
    //METHOD-1
    //NORMAL SLIDIING WINDOW
    int numberOfSubstrings(string s) 
    {
        int n= s.size();
        vector<int>mp(3,0);
        int l=0,r=0,ans=0;
        while(r<n)
        {
            mp[s[r]-'a']++;
            while(mp[0]>0 && mp[1]>0 && mp[2]>0)
            {
                ans+= n-r;
                mp[s[l]-'a']--;
                l++;
            }
            r++;
        }   
        return ans;
    }
*/