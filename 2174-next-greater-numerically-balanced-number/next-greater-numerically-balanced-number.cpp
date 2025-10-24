class Solution {
public:
    //METHOD-1
    //Simple Approach..
    bool balanced(int n)
    {
        vector<int>freq(10,0);
        while(n>0)
        {
            freq[n%10]++;
            n/=10;
        }
        for(int i=0;i<10;i++)
        {
            if(freq[i]==0)
            {
                continue;
            }
            else if(freq[i]!=i)
            {
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) 
    {
        for(int i=n+1;i<=1224444;i++)
        {
            if(balanced(i))
            {
                return i;
            }
        }
        return -1;
    }
};