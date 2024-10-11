class Solution {
public:
    // static bool cmp(const vector<int>&a, const vector<int>&b)
    // {
    //     if(a[0]!=b[0])
    //     {
    //         return a[0]<b[0];
    //     }
    //     return a[1]<b[1];
    // }
    int smallestChair(vector<vector<int>>& time, int fri) 
    {
        int n= time.size();
        vector<int>chair(n,-1);
        int arrif= time[fri][0];
        sort(time.begin(),time.end());

        for(auto e:time)
        {
            int arrival= e[0];
            int dep= e[1];
            for(int i=0;i<n;i++)
            {
                if(chair[i]<=arrival)
                {
                    chair[i]=dep;
                    //we can say this as given that arrival time is distinct of all friends
                    if(arrif==arrival)
                    {
                        return i;
                    }
                    break;
                }
            }
        }
        return -1;
    }
};