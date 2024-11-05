class Solution {
public:
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
};