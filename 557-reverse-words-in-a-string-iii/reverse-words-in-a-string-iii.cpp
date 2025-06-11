class Solution {
public:
    //METHOD-1
    //Using stringstream..
    string reverseWords(string s) 
    {
        string ans="";
        string temp="";
        for(auto i:s)
        {
            if(i!=' ')
            {
                temp+=i;
            }
            else
            {
                if(temp!="")
                {
                    reverse(temp.begin(),temp.end());
                    ans+= temp;
                    ans+=' ';
                    temp="";
                }
            }
        }
        if(temp!="")
        {
            reverse(temp.begin(),temp.end());
            ans+= temp;
        }
        return ans;
    }
};