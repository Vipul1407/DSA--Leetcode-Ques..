class Solution {
public:
    int findGCD(vector<int>& nums) 
    {
        int b= *min_element(nums.begin(),nums.end());//min
        int a= *max_element(nums.begin(),nums.end());//max

        //finding gcd of both numbers
        //a>b 
        while(b!=0)
        {
            int rem= a%b;
            a=b;
            b=rem;
        }
        return a;
    }
};