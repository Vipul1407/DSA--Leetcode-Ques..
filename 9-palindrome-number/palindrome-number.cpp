class Solution {
public:
    bool isPalindrome(int x)
    {
        long long rev=0;
        int y=x;
        while(y>0)
        {
            rev= rev*10+ (y%10);
            y/=10;
        }
        return (int)rev==x;
    }
};