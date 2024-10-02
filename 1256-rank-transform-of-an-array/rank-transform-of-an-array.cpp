class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& num) 
    {
        int n= num.size();
        if(n==0)
        {
            return num;
        }
        vector<int>arr= num;
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        int cnt=1;
        for(int i=0;i<n-1;i++)
        {
            mp[arr[i]]=cnt;
            if(arr[i+1]!=arr[i])
            {
                cnt++;
            }
        }
        mp[arr[n-1]]=cnt;
        vector<int>ans;
        for(auto i:num)
        {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};