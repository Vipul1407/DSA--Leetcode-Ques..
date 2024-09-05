class Solution {
public:
    string fractionAddition(string exp) 
    {
        int num=0;
        int den=1;
        int n= exp.length();
        int i=0;
        while(i<n)
        {
            int currnum=0;
            int currden=0;
            bool neg= exp[i]=='-';
            if(exp[i]=='-' || exp[i]=='+')
            {
                i++;
            }
            while(i<n && isdigit(exp[i]))
            {
                int val= exp[i]-'0';
                currnum= (currnum*10)+val;// multiply by 10 makes our work as it is given that exp[i] is from 1 to 10
                i++;
            }
            i++;//to skip '/' sign
            if(neg==true)
            {
                currnum*=-1;
            }
            while(i<n && isdigit(exp[i]))
            {
                int val= exp[i]-'0';
                currden= (currden*10)+val;
                i++;
            }
            num= num*currden + currnum*den;
            den= den*currden; 
        }
        
        //to make it in simplest form
        int g= abs(gcd(num,den));
        num/=g;
        den/=g;
        return to_string(num)+"/"+to_string(den);
    }
};