class Solution {
public:

    //APPROACH USING MIN PLATFORM NEEDED QUES...
    int minGroups(vector<vector<int>> &inter)
    {
        int n= inter.size();
        int pneed=1;
        int ans=1;
        int i=1;//start from 1
        int j=0;
        vector<int>arrival;
        vector<int>dep;
        for(auto i:inter)
        {
            arrival.push_back(i[0]);
            dep.push_back(i[1]);
        }
        sort(arrival.begin(),arrival.end());
        sort(dep.begin(),dep.end());
        while(i<n && j<n)
        {
            //less than equal becoz we need a new platform if arrival time = prev dep time..
            if(arrival[i]<=dep[j])
            {
                i++;
                pneed++;
                ans= max(ans,pneed);
            }
            else
            {
                j++;
                pneed--;
            }
        }
        return ans;
    }
/*
    // METHOD-1
    //  BRUTE FORCE..
    int minGroups(vector<vector<int>> &inter)
    {
        int n = inter.size();
        sort(inter.begin(), inter.end());
        vector<int> arr;
        for (auto i : inter)
        {
            bool flag = false;
            int arri = i[0];
            int dep = i[1];
            for (int j = 0; j < arr.size(); j++)
            {
                if (arri > arr[j])
                {
                    arr[j] = dep;
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                arr.push_back(dep);
            }
        }
        return arr.size();
    }

    //METHOD-2
    //OPTIMIZED USING PRIORITY QUEUE..
    int minGroups(vector<vector<int>>& inter) 
    {
        int n=inter.size();
        //min heap storing departure
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(inter.begin(),inter.end());
        
        for(auto i:inter)
        {
            int arri= i[0];
            int dep= i[1];
            if(pq.size() && arri>pq.top())
            {
                pq.pop();
            }
            pq.push(dep);
        }
        return pq.size();
    }
*/
};