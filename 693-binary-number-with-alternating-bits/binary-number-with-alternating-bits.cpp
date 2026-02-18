class Solution {
public:
    bool hasAlternatingBits(int n) 
    {
        int f= -1;
        while(n>0)
        {
            int bit= n&1;
            if(bit==f)
            {
                return false;
            }
            f= bit;
            n>>=1;
        }
        return true;
    }
};