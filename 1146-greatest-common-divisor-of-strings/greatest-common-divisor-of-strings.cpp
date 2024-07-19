class Solution {
public:
    int gcd(int a, int b)
    {
        while(b!=0)
        {
            int rem= a%b;
            a=b;
            b=rem;
        }
        return a;
    }
    string gcdOfStrings(string a, string b) 
    {
        if(a+b!=b+a)
        {
            return "";
        }
        int g= gcd(a.length(),b.length());
        //starting index, length
        return a.substr(0,g);
    }
};