class Solution 
{
public:
    bool canChange(string str, string tar) 
    {
        int n= str.size();
        int i=0;
        int j=0;
        while(i<n || j<n)
        {
            while(i<n && str[i]=='_')
            {
                i++;
            }
            while(j<n && tar[j]=='_')
            {
                j++;
            }
            if(i==n && j==n)
            {
                return true;
            }
            if(str[i]!=tar[j])
            {
                return false;
            }
            else if(str[i]=='L' && i<j)
            {
                return false;
            }
            else if(str[i]=='R' && i>j)
            {
                return false;
            }
            i++;j++;
        }
        return true;
    }
};