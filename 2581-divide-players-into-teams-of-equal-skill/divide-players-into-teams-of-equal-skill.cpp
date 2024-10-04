class Solution {
public:
    long long dividePlayers(vector<int>& skill) 
    {
        long long chem=0;
        sort(skill.begin(),skill.end());
        int i=0;
        int n= skill.size();
        int j=n-1;
        int sum=skill[i]+skill[j];
        while(i<j)
        {
            if(sum!=skill[i]+skill[j])
            {
                return -1;
            }
            chem+= skill[i]*skill[j];
            i++;
            j--;
        }
        return chem;
    }
};