class Solution {
public:
    //METHOD-1
    //Using stringstream..
    string reverseWords(string str) 
    {
        stringstream ss(str);
        string temp;
        string ans="";
        while(ss>>temp)
        {
            reverse(temp.begin(),temp.end());
            ans+= temp;
            ans+= ' ';
        }
        if(ans.back()==' ')
        {
            ans.pop_back();
        }
        return ans;
    }
};