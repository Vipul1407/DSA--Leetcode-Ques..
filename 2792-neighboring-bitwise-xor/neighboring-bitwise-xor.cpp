class Solution {
public:
    //METHOD-2
    bool doesValidArrayExist(vector<int>& derived) 
    {
        int n= derived.size();
        int cnt1= 0;
        for(int i=0;i<n;i++)
        {
            if(derived[i]==1)
            {
                cnt1++;
            }
        }
        //if no. of 1's are even then xor=0 and will return true..
        return cnt1%2==0;
    }
};
/*
// METHOD-1
// BEATS 25%
bool doesValidArrayExist(vector<int> &derived)
{
    int n = derived.size();
    vector<int> original(n, 0);
    for (int i = 1; i < n; i++)
    {
        original[i] = derived[i - 1] ^ original[i - 1];
    }
    return original[0] ^ original[n - 1] == derived[n - 1];
}
//METHOD-2
//BEATS 100%
bool doesValidArrayExist(vector<int>& derived) 
{
    int n= derived.size();
    int xorv=derived[0];
    for(int i=1;i<n;i++)
    {
        xorv^=derived[i];
    }
    return xorv==0;
}
*/