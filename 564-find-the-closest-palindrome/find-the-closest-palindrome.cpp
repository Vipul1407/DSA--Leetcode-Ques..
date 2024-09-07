class Solution {
public:
    long solve(long half, bool iseven)
    {
        long num= half;
        if(iseven == false)
        {
            //leaving middle as pivot only in case of odd
            half/=10;
        }
        while(half>0)
        {
            int digit= half%10;
            num= (num*10)+digit;
            half/=10;
        }
        return num;
    }
    string nearestPalindromic(string s) 
    {
        int n=s.length();
        int mid= n/2;
        //agar even length h to mid tk length lenge 
        int halflen= (n%2==0)? mid: (mid+1);
        //agar odd length h to mid+1 tk length lenge
        long half= stol(s.substr(0,halflen));
        vector<long>res;
        res.push_back(solve(half, n%2==0));
        res.push_back(solve(half+1, n%2==0));
        res.push_back(solve(half-1, n%2==0));
        //to handle case of 101 ---> 10^2 -1= 99
        res.push_back((long)pow(10,n-1)-1);
        //to handle case of 999 ---> 10^3 +1= 1001
        res.push_back((long)pow(10,n)+1);

        long diff= INT_MAX;
        long ans= INT_MAX;
        long original= stol(s);
        for(long i:res)
        {
            if(i==original)
            {
                continue;
            }
            if(abs(i-original)<diff)
            {
                diff= abs(i-original);
                ans=i;
            }
            else if(abs(i-original)==diff)
            {
                ans= min(ans,i);
            }
        }
        return to_string(ans);
    }
}; 