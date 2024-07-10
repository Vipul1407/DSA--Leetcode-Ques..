class Solution {
public:
    int romanToInt(string s) 
    {
        int n=s.length();
        int ans=0;

        for(int i=0;i<n;i++)
        {
            if(i<n-1)
            {
                string str="";
                str+= s[i];
                str+= s[i+1];
                if(str=="IV")
                {
                    i++;
                    ans+=4;
                }
                else if(str=="IX")
                {
                    i++;
                    ans+=9;
                }
                else if(str=="XL")
                {
                    i++;
                    ans+=40;
                }
                else if(str=="XC")
                {
                    i++;
                    ans+=90;
                }
                else if(str=="CD")
                {
                    i++;
                    ans+=400;
                }
                else if(str=="CM")
                {
                    i++;
                    ans+=900;
                }
                else if(s[i]=='I')
                {
                    ans+= 1;
                }
                else if(s[i]=='V')
                {
                    ans+= 5;
                }
                else if(s[i]=='X')
                {
                    ans+= 10;
                }
                else if(s[i]=='L')
                {
                    ans+= 50;
                }
                else if(s[i]=='C')
                {
                    ans+= 100;
                }
                else if(s[i]=='D')
                {
                    ans+= 500;
                }
                else if(s[i]=='M')
                {
                    ans+= 1000;
                }
            }
            //i==n-1
            else
            {
                if(s[i]=='I')
                {
                    ans+= 1;
                }
                else if(s[i]=='V')
                {
                    ans+= 5;
                }
                else if(s[i]=='X')
                {
                    ans+= 10;
                }
                else if(s[i]=='L')
                {
                    ans+= 50;
                }
                else if(s[i]=='C')
                {
                    ans+= 100;
                }
                else if(s[i]=='D')
                {
                    ans+= 500;
                }
                else if(s[i]=='M')
                {
                    ans+= 1000;
                }
            }
        }

        return ans;
    }
};