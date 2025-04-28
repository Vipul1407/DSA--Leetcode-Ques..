class Solution {
public:
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
};