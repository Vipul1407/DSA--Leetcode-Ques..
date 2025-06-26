class Solution {
public:
    int longestSubsequence(string s, int k) 
    {
        int n= s.size();
        int i=0;
        int val=0;
        while(i<min(32,n))
        {
            if(s[n-i-1]=='1')
            {
                if(val+ pow(2,i)>k)
                {
                    break;
                }
                val+= pow(2,i);
            }
            i++;
        }
        int remove=0;
        while(i<n)
        {
            if(s[n-i-1]=='1')
            {
                remove++;
            }
            i++;
        }
        return n-remove;
    }
};