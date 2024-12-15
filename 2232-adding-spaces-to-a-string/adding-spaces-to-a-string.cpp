class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) 
    {
        int n= s.size();
        int m= spaces.size();
        int k=0;//to traverse on spaces
        int i=0;//to traverse on s
        string ans="";
        while(i<n && k<m)
        {
            if(i!=spaces[k])
            {
                ans+= s[i];
            }
            else
            {
                ans+=" ";
                ans+=s[i];
                k++;
            }
            i++;
        }
        while(i<n)
        {
            ans+=s[i];
            i++;
        }
        return ans;
    }
};