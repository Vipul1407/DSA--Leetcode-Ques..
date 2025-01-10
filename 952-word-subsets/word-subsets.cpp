class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        vector<string>ans;
        //making final cnt vector of words2..
        vector<int>subset(26,0);
        for(auto i:words2)
        {
            //we have to take max cnt of that particular element..
            vector<int>temp(26,0);
            for(auto j:i)
            {
                temp[j-'a']++;
                subset[j-'a']= max(subset[j-'a'],temp[j-'a']);
            }
        }
        for(auto i:words1)
        {
            vector<int>cnt(26,0);
            int flag=1;
            for(auto j:i)
            {
                cnt[j-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                //cnt of that element in cnt vector must be >= cnt of that element in subset vector
                if(cnt[i]<subset[i])
                {
                    flag=0;
                }
            }
            if(flag==1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};