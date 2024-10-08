class Solution {
public:
    int minSwaps(string s) 
    {
        int openingb=0;//opening_bracket
        for(auto i:s)
        {
            if(i=='[')
            {
                openingb++;
            }
            else if(openingb>0)
            {
                openingb--;
            }
        }
        return (1+openingb)/2;
    }
};