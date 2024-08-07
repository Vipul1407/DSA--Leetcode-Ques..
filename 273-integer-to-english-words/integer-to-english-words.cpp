class Solution {
public:

    vector<string>belowten={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    vector<string>belowtwenty={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string>belowhundred={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

    string solve(int n) 
    {
        if(n<10)
        {
            return belowten[n];
        }
        if(n<20)
        {
            return belowtwenty[n-10];
        }
        if(n<100)
        {
            return belowhundred[n/10]+ ((n%10!=0)? " "+solve(n%10) : "");
        }
        if(n<1000)
        {
            //879
            return solve(n/100)+" Hundred"+((n%100!=0)? " "+solve(n%100): "");
        }
        //less than 1million = 10lakh= 10^6
        if(n<1000000)
        {
            return solve(n/1000)+" Thousand"+((n%1000!=0)? " "+solve(n%1000): "");
        }
        //less than 1 billion = 100crores= 10^9
        if(n<1000000000)
        {
            return solve(n/1000000)+" Million"+((n%1000000!=0)? " "+solve(n%1000000): "");
        }
        else
        {
            return solve(n/1000000000)+" Billion"+((n%1000000000)? " "+solve(n%1000000000): "");
        }
    }

    string numberToWords(int n) 
    {
        if(n==0)
        {
            return "Zero";
        }
        return solve(n);
    }
};
