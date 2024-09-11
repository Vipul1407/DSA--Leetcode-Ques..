
class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int cnt = 0;
        // NOW QUES IS EXACTLY SAME AS MIN FLIP TO CONVERT NUMBER
        while (a > 0 || b > 0 || c>0)
        {
            int bitA= a%2;
            int bitB= b%2;
            int bitC= c%2;
            if(bitC==0)
            {
                cnt+= bitA + bitB;
            }
            else
            {
                if(bitA==0 && bitB==0)
                {
                    cnt++;
                }
            }
            a /= 2;
            b /= 2;
            c/=2;
        }
        return cnt;
    }
};