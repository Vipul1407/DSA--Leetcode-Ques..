class Solution {
public:
    //METHOD-2
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
*/