class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        int cnt=0;
        while(start>0 && goal>0)
        {
            if((start%2==0 && goal%2==1) || (start%2==1 && goal%2==0))
            {
                cnt++;
            }
            start/=2;
            goal/=2;
        }
        while(start>0)
        {
            if(start%2==1)
            {
                cnt++;
            }
            start/=2;
        }
        while(goal>0)
        {
            if(goal%2==1)
            {
                cnt++;
            }
            goal/=2;
        }
        return cnt;
    }
};