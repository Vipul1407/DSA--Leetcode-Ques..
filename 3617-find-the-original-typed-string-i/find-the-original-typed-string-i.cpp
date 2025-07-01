class Solution {
public:
    int possibleStringCount(string word) 
    {
        int ans=1;//to count curr string..
        int n= word.size();
        for(int i=1;i<n;i++)
        {
            if(word[i]==word[i-1])
            {
                ans++;
            }
        }
        return ans;
    }
};