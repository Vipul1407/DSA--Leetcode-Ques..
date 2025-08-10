class Solution {
public:
    //METHOD-1
    //Using set..
    bool reorderedPowerOf2(int n) 
    {
        //unordered_set<string>st;
        for(int p=0;p<=29;p++)
        {
            string powertwo= to_string(1<<p);
            sort(begin(powertwo),end(powertwo));
            string str= to_string(n);
            sort(begin(str),end(str));
            if(powertwo==str)
            {
                return true;
            }
        }
        return false;
    }
};