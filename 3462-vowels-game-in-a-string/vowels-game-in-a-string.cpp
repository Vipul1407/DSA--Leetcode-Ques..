class Solution {
public:
    bool doesAliceWin(string s) 
    {
        //if atleast 1 vowel==> then Alice will win..
        for(auto i:s)
        {
            if(i=='a' || i=='e' || i=='i' || i=='o' || i=='u')
            {
                return true;
            }
        }
        //bob wins..
        return false;
    }
};