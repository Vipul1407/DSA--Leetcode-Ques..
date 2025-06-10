class Solution {
public:
    //METHOD-1
    //BRUTE FORCE...
    string reverseWords(string s) 
    {
        int n= s.size();
        string temp="";
        string ans;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==' ')
            {
                if(temp!="")
                {
                    reverse(temp.begin(),temp.end());
                    if(!ans.empty())
                    {
                        ans+=' ';
                    }
                    ans+= temp;
                    temp="";
                }
                else
                {
                    continue;
                }
            }
            else
            {
                temp+= s[i];
            }
        }
        if(temp!="")
        {       
            reverse(temp.begin(),temp.end());
            if(!ans.empty())
            {
                ans+=' ';
            }
            ans+= temp;
        }
        return ans;
    }
};