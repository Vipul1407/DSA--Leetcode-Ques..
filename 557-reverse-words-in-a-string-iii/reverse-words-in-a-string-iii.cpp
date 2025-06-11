class Solution {
public:
    //METHOD-2
    //OPTIMIZED..
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
/*
    //  METHOD-1
    //  Using stringstream..
    string reverseWords(string str)
    {
        stringstream ss(str);
        string temp;
        string ans = "";
        while (ss >> temp)
        {
            reverse(temp.begin(), temp.end());
            ans += temp;
            ans += ' ';
        }
        if (ans.back() == ' ')
        {
            ans.pop_back();
        }
        return ans;
    }


    
// METHOD-3
string reverseWords(string str)
{
    int n = str.size();
    int start = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i == n || str[i] == ' ')
        {
            reverse(str.begin() + start, str.begin() + i);
            start = i + 1;
        }
    }
    return str;
}

// METHOD-4
string reverseWords(string s)
{
    int n = s.length();
    int low = 0;
    int high = 0;
    while (low < n)
    {
        while (high < n && s[high] != ' ')
        {
            high++;
        }
        reverse(s.begin() + low, s.begin() + high);
        low = high + 1;
        high = low;
    }
    return s;
}
*/