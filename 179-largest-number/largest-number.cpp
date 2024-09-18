class Solution {
public:

    static bool cmp(string &a, string&b)
    {
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) 
    {
        vector<string>vec;
        for(auto i:nums)
        {
            //will not do this as we need to maintain thedigits coming itself...
            // int num=i;
            // while(num>0)
            // {
            //     vec.push_back(num%10);
            //     num/=10;
            // }
            vec.push_back(to_string(i));
        }    
        sort(vec.begin(),vec.end(),cmp);
        if(vec[0]=="0")
        {
            return "0";//to get correct ans when we have input as [0,0,0,0] then we need to return only "0"
        }
        string ans="";
        for(auto i:vec)
        {
            ans+= i;
        }
        return ans;
    }
};