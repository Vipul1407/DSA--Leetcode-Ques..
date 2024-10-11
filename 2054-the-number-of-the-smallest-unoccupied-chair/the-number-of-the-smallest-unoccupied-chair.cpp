class Solution {
public:
    int smallestChair(vector<vector<int>>& time, int fri)
    {
        int n= time.size();
        int curr=0;//storing curr chair
        //min heap storing departure time, curr chair
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //min heap storing free chair
        priority_queue<int,vector<int>,greater<int>>free;

        int arrif= time[fri][0];//storing friend's arrivall time..
        sort(time.begin(),time.end());
        for(auto e:time)
        {
            int arrival= e[0];
            int dep= e[1];
            //if departure<=arrival
            while(pq.size() && pq.top().first<=arrival)
            {
                free.push(pq.top().second);//to store curr free chair
                pq.pop();
            }
            if(free.size())
            {
                if(arrif== arrival)
                {
                    return free.top();
                }
                pq.push({dep,free.top()});
                free.pop();
            }
            else
            {
                if(arrif== arrival)
                {
                    return curr;
                }
                pq.push({dep,curr});
                curr++;
            }
        }
        return -1;
    }
};

//BRUTE FORCE------------------>O(N^2)

/*class Solution {
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
};*/