class Solution {
public:
    string addBinary(string a, string b) 
    {
        int n= a.size()-1;
        int m= b.size()-1;
        int sum=0,carry=0;
        string ans="";

        while(n>=0 || m>=0 || carry>0)
        {
            sum= carry;
            if(n>=0)
            {
                sum+= (a[n]-'0');
                n--;
            }
            if(m>=0)
            {
                sum+= (b[m]-'0');
                m--;
            }

            ans+= (sum%2)+'0';
            carry= sum/2;
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};