class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) 
    {
        int i=0;
        int j=0;
        int n= str1.size();
        while(i<n)
        {
            if(str1[i]==str2[j] || ((str1[i]-'a'+1)%26+'a' == str2[j]) || ((str1[i]-'a'-25)%26+'a' == str2[j]))
            {
                j++;
            }
            i++;
        }
        return j== str2.size();
    }
};