class Solution {
public:
    //TC= O(NLOGN + NLOGN)
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        int n= envelopes.size();
        sort(begin(envelopes),end(envelopes),[](auto &a, auto &b)
        {
            return a[0]!=b[0]? a[0]<b[0]: a[1]>b[1];
        });
        vector<int>ans;
        ans.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++)
        {
           if(envelopes[i][1]>ans.back())
           {
                ans.push_back(envelopes[i][1]);
           }
           else
           {
                //lower bound nikal nums[i] ka ans vector me..
                int just_greater_index= lower_bound(begin(ans),end(ans),envelopes[i][1])- begin(ans);
                ans[just_greater_index]= envelopes[i][1];
           }
        }
        //only length is corect but the order is wrong...
        return ans.size();
    }
};