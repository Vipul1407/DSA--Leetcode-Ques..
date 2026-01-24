class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        sort(begin(people),end(people));
        int l= 0;
        int r= people.size()-1;
        int ans=0;
        while(l<=r)
        {
            if(people[l]+people[r]<=limit)
            {
                l++;
                r--;
            }
            else
            {
                r--;
            }
            ans++;
        }
        return ans;
    }
};