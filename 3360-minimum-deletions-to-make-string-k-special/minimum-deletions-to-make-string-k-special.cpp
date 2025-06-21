class Solution {
public:
    //METHOD-2
    //Using sorting...
    int minimumDeletions(string word, int k) 
    {
        int n= word.size();
        vector<int>vec(26,0);
        for(auto i:word)
        {
            vec[i-'a']++;
        }
        sort(vec.begin(),vec.end());
        int ans= n;
        int commdel =0;
        //we are assuming number to be in range of vec[i]---vec[i]+k
        for(int i=0;i<26;i++)
        {
            int del= commdel;
            for(int j=25;j>i;j--)
            {
                if(vec[j]-vec[i]<=k)
                {
                    break;
                }
                del+= vec[j]-vec[i]-k;
            }
            ans= min(ans,del);
            commdel+= vec[i];
        }
        return ans==INT_MAX? 0:ans;
    }
};
/*
    //METHOD-1
    //Without using sorting...
    int minimumDeletions(string word, int k) 
    {
        int n= word.size();
        vector<int>vec(26,0);
        for(auto i:word)
        {
            vec[i-'a']++;
        }
        int ans=INT_MAX;
        //we are assuming number to be in range of vec[i]---vec[i]+k
        for(int i=0;i<26;i++)
        {
            int del=0;
            for(int j=0;j<26;j++)
            {
                if(i==j)
                {
                    continue;
                }
                //delete vec[j] fully
                if(vec[j]<vec[i])
                {
                    del+= vec[j];
                }
                else if(abs(vec[j]-vec[i])>k)
                {
                    del+= abs(vec[j]-vec[i]-k);
                }
            }
            ans= min(ans,del);
        }
        return ans==INT_MAX? 0:ans;
    }
*/