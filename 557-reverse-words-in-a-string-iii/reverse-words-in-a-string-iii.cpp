class Solution {
public:
    //METHOD-2
    string reverseWords(string str) 
    {
        int n= str.size();
        string ans="";
        string temp="";
        for(int i=0;i<n;i++)
        {
            if(str[i]==' ')
            {
                reverse(temp.begin(),temp.end());
                ans+= temp;
                ans+=' ';
                temp="";
            }
            else
            {
                temp+= str[i];
            }
        }
        reverse(temp.begin(),temp.end());
        ans+= temp;
        return ans;
    }
};
/*
    //METHOD-1
    //Using StringStream..
    string reverseWords(string str) 
    {
        int n= str.size();
        stringstream ss(str);
        string temp="";
        string ans="";
        int flag=0;
        while(getline(ss,temp,' '))
        {
            if(flag==0)
            {
                flag=1;
            }
            else
            {
                ans+= ' ';
            }
            reverse(temp.begin(),temp.end());
            ans+= temp;
        }
        return ans;
    }
*/