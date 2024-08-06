class Solution {
public:
    int minimumPushes(string word) 
    {
        unordered_map<char,int>mp;
        //8-->single letter
        //8-->double digit
        //8-->triple digit
        //2-->4 digits
        for(auto i:word)
        {
            mp[i]++;
        } 
        vector<int>vec;
        for(auto i:mp)
        {
            vec.push_back(i.second);
        }
        sort(vec.begin(),vec.end());
        int cnt=0;
        int ans=0;
        for(auto i:vec)
        {
            cnt++;
            if(cnt<=8)
            {
                ans+= i;
            }
            else if(cnt<=16)
            {
                ans+= i*2;
            }
            else if(cnt<=24)
            {
                ans+= i*3;
            }
            else
            {
                ans+= i*4;
            }
        }
        return ans;
    }
};