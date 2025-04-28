class Solution {
public:
    //METHOD-3
    string reverseWords(string str) 
    {
        int n= str.size();
        int start=0;
        for(int i=0;i<=n;i++)
        {
            if(i==n || str[i]==' ')
            {
                reverse(str.begin()+start,str.begin()+i);
                start= i+1;
            }
        }
        return str;
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
*/