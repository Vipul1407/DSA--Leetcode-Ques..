class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int c5=0;
        int c10=0;
        for(auto i:bills)
        {
            if(i==5)
            {
                c5++;
            }
            else if(i==10)
            {
                c10++;
                if(--c5<0)
                {
                    return false;
                }
            }
            else if(i==20)
            {
                //get change in 2 ways-:
                //5+5+5 or 10+5
                if(c10>0 && c5>0)
                {
                    c10--;
                    c5--;
                }
                else if(c5>=3)
                {
                    c5-=3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};