class Solution {
public:
    string addBinary(string a, string b) {
        int n1= a.length()-1;
        int n2= b.length()-1;

        int sum= 0, carry= 0;
        string ans= "";
        while(n1 >= 0 || n2 >= 0)
        {
            sum= carry;
            if(n1 >= 0) 
            {
                sum+= a[n1]-'0';
                n1--;
            }

            if(n2 >= 0)
            {
                sum+= b[n2]-'0';
                n2--;
            }

            if(sum % 2 == 0) {
                ans+= '0';
            }
            else{
                ans+= '1';
            }

            carry= sum/2;
        }

        if(carry > 0) ans+= '1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};