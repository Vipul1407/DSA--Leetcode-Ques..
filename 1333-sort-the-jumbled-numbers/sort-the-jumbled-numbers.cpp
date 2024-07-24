class Solution {
public:
    static bool cmp(const pair<int,int>&a, const pair<int,int>&b)
    {
        return a.second<b.second;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) 
    {
        vector<pair<int,int>>vec;
        vector<int>ans;
        for(auto i:nums)
        {
            int original=i;
            int form=0;
            int place=1;
            if(i==0)
            {
                form= mapping[0];//place original no.
            }
            else
            {
                while(i>0)
                {
                    form+= mapping[i%10]*place;
                    i/=10;
                    place*=10;
                }
            }
            vec.push_back({original,form});//we are pushing original mapping, formed integer as 
            //  in sorting to keep relative order if same formed integer
        }
        sort(vec.begin(),vec.end(),cmp);
        for(auto i:vec)
        {
            ans.push_back({i.first});
        }
        return ans;
    }
};