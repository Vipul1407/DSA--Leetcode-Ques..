class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) 
    {
        int i=0;
        int j=0;
        int n= str1.size();
        while(i<n)
        {
            if(str1[i]==str2[j] || (str1[i]+1 == str2[j]) || (str1[i]-25 == str2[j]))
            {
                j++;
            }
            i++;
        }
        return j== str2.size();
    }
};
/*

// METHOD-1
bool canMakeSubsequence(string str1, string str2)
{
    int i = 0;
    int j = 0;
    int n = str1.size();
    while (i < n)
    {
        if (str1[i] == str2[j] || ((str1[i] - 'a' + 1) % 26 + 'a' == str2[j]) || ((str1[i] - 'a' - 25) % 26 + 'a' == str2[j]))
        {
            j++;
        }
        i++;
    }
    return j == str2.size();
}

// METHOD-2
bool canMakeSubsequence(string source, string target)
{
    int targetIdx = 0;
    int targetLen = target.length();
    for (char currChar : source)
    {
        if (targetIdx < targetLen && (target[targetIdx] - currChar + 26) % 26 <= 1)
        {
            targetIdx++;
        }
    }
    return targetIdx == targetLen;
}
*/