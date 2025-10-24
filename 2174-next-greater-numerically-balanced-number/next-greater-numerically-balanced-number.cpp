class Solution {
public:
    //METHOD-2
    //Backtracking...
    //TC= O(9^(LOG n)) we have 9 options each for log(n)= 7 digits at max..
    int solve(int curr, int &n, int len, vector<int>&freq)
    {
        if(len==0)
        {
            for(int i=1;i<10;i++)
            {
                if(freq[i]!=0 && freq[i]!=i)
                {
                    return 0;
                }
            }
            return curr>n ? curr:0;
        }
        int ans=0;
        for(int i=1;i<10;i++)
        {
            freq[i]--;
            ans= solve(curr*10+i, n, len-1, freq);
            freq[i]++;//backtracking...
            if(ans!=0)
            {
                break;
            }
        }
        return ans;
    }
    int nextBeautifulNumber(int n) 
    {
        int len= to_string(n).size();
        vector<int>freq={0,1,2,3,4,5,6,7,8,9};
        int res= solve(0,n,len,freq);
        if(res==0)
        {
            return solve(0,n,len+1,freq);
        }
        return res;
    }
};
/*
    //METHOD-1
    //Simple Approach..
    //TC= O(1224444* LOG(n))
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
*/