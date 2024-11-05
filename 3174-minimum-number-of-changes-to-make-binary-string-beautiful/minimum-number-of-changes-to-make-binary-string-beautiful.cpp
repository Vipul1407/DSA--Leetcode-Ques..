class Solution {
public:
    int minChanges(string s) 
    {
        int n=s.size();
        int cnt=0;//count of that consecutive char will start from 0 not 1
        char prev= s[0];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==prev)
            {
                cnt++;
            }
            else
            {
                if(cnt%2==0)
                {
                    cnt=1;
                }
                else
                {
                    cnt=0;
                    ans++;
                }
                prev=s[i];
            }
        }   
        return ans;
    }
};

/*
    int minChanges(string s) 
    {
        int x=0;//cnt of 0
        int y=0;//cnt of 1
        int n= s.size();
        int ans=0;
        for(int i=0;i<n;i+=2)
        {
            if(s[i]=='1')
            {
                y++;
            }
            else 
            {
                x++;
            }
            if(s[i+1]=='1')
            {
                y++;
            }
            else
            {
                x++;
            }
            ans+= min(x%2, y%2);
            x=0;
            y=0;
        }
        return ans;
    }
*/