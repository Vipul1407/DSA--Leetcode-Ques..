class Solution {
public:
    //METHOD-2
    //TC= O(N) USING IF
    int totalFruit(vector<int>& fruits) 
    {
        int n= fruits.size();
        unordered_map<int,int>mp;
        int l=0,r=0,ans=0;
        while(r<n)
        {
            mp[fruits[r]]++;
            if(l<r && mp.size()>2)
            {
                if(--mp[fruits[l]]==0)
                {
                    mp.erase(fruits[l]);
                }
                l++;
            }
            if(mp.size()<=2)
            {
                ans= max(ans,r-l+1);
            }       
            r++;
        }
        return ans;
    }
};
/*
    //METHOD-1
    //TC= O(2N) USING WHILE
    int totalFruit(vector<int>& fruits) 
    {
        int n= fruits.size();
        unordered_map<int,int>mp;
        int l=0,r=0,ans=0;
        while(r<n)
        {
            mp[fruits[r]]++;
            while(l<r && mp.size()>2)
            {
                if(--mp[fruits[l]]==0)
                {
                    mp.erase(fruits[l]);
                }
                l++;
            }
            ans= max(ans,r-l+1);    
            r++;
        }
        return ans;
    }
*/