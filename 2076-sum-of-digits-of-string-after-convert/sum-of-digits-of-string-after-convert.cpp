class Solution {
public:
    int getLucky(string s, int k) 
    {
        string ans="";
        for(auto i:s)
        {
            ans+= to_string(i-'a' + 1);
        }
        string repeat= ans;
        int sum=0;
        while(k--)
        {
            sum=0;
            for(auto i:repeat)
            {
                sum+= i-'0';
            }
            repeat= to_string(sum);
        }
        return sum;
    }
};