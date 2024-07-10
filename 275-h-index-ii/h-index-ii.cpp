class Solution {
public:
    int hIndex(vector<int>& cit) 
    {
        int i=0;
        int n=cit.size();
        while(i<n && cit[i]<n-i)
        {
            i++;
        }
        return n-i;
    }
};