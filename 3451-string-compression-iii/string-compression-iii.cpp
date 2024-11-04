class Solution {
public:
    string compressedString(string word) 
    {
        int n=word.size();
        int cnt=1;
        string ans="";
        for(int i=1;i<n;i++)
        {
            if(word[i-1]==word[i])
            {
                cnt++;
            }
            else
            {
                while(cnt>9)
                {
                    ans+= "9";
                    ans+=word[i-1];
                    cnt-=9;
                }
                //to add remainder when cnt<9
                if(cnt>0)
                {
                    ans+= to_string(cnt);
                    ans+=word[i-1];
                }
                cnt=1;
            }
        }
        //handling last character
        while(cnt>9)
        {
            ans+= "9";
            ans+=word[n-1];
            cnt-=9;
        }
        //to add remainder when cnt<9
        if(cnt>0)
        {
            ans+= to_string(cnt);
            ans+=word[n-1];
        }
        return ans;
    }
};