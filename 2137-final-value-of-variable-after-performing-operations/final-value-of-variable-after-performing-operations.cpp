class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) 
    {
        int ans=0;
        for(auto i:operations)
        {
            if(i== "X++")
            {
                ans++;
            }
            else if(i== "++X")
            {
                ++ans;
            }
            else if(i== "X--")
            {
                ans--;
            }
            else
            {
                --ans;
            }
        }    
        return ans;
    }
};