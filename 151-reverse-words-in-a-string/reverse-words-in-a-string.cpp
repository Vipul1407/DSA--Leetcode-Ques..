class Solution {
public:
    //METHOD-2
    //Using Stringstream..
    string reverseWords(string str) 
    {
        int n= str.size();
        //it will automatically cut all leading and trailing spaces..
        stringstream ss(str);
        string ans="";
        string temp;
        while(ss>>temp)
        {
            ans= temp+" "+ans;
        }
        if(ans.back()==' ')
        {
            ans.pop_back();
        }
        return ans;
    }
};
/*
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
*/