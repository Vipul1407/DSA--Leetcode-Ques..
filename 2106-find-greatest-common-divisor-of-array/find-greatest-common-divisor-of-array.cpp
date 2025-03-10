class Solution {
public:
    int gcd(int a, int b)
    {
        if(b==0)
        {
            return a;
        }
        return gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) 
    {
        int b= *min_element(nums.begin(),nums.end());//min
        int a= *max_element(nums.begin(),nums.end());//max

        //finding gcd of both numbers
        //a>b 
        return gcd(b,a);
    }
};