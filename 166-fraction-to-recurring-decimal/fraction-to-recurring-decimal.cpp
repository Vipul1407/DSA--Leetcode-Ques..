class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) 
    {
        string ans="";
        if(numerator==0)
        {
            return "0";
        }
        if((numerator<0 && denominator<0) || (numerator>0 && denominator>0))
        {
    
        }
        else
        {
            ans+='-';
        }
        long long num= llabs((long long)numerator);
        long long den= llabs((long long)denominator);
        ans+= to_string(num/den);
        long long rem= num%den;
        if(rem==0)
        {
            return ans;
        }
        ans+='.';
        unordered_map<int,long long>mp;
        while(rem!=0)
        {
            if(mp.count(rem))
            {
                ans.insert(mp[rem],"(");
                ans+=")";
                break;
            }
            mp[rem]= ans.size();
            rem*=10;
            ans+= to_string(rem/den);
            rem%=den;
        }
        return ans;
    }
};