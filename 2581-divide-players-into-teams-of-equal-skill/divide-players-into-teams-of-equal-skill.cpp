class Solution {
public:
    long long dividePlayers(vector<int>& skill) 
    {
        int n=skill.size();
        long long chem=0;
        int sum= accumulate(skill.begin(),skill.end(),0);
        if(sum% (n/2)!=0)
        {
            return -1;
        }
        int size= sum/(n/2);
        vector<int>mp(1001,0);
        for(auto i:skill)
        {
            mp[i]++;
        }
        for(auto i:skill)
        {
            if(mp[i]==0)
            {
                continue;
            }
            int remain= size-i;
            if(mp[remain]>0)
            {
                chem+= (long long)i*(long long)remain;
                mp[remain]--;
                mp[i]--;
            }
            else
            {
                return -1;
            }
        }
        return chem;
    }
};