class Solution {
public:
    //Hierholzer's Algorithm
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) 
    {
        //starting pt. of euler graph is that where
        //outdegree-indegree= 1
        //ending point of euler graph is that where
        //indegree- outdegree= 1
        //euler graph can be traced only once..
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>degree;//storing outdegree-indegree
        for(auto i:pairs)
        {
            mp[i[0]].push_back(i[1]);
            degree[i[0]]++;
            degree[i[1]]--;
        }
        int start=pairs[0][0];//i case we do not have a start node take any node as start
        for(auto i:degree)
        {
            if(i.second==1)
            {
                start= i.first;
                break;
            }
        }
        //applying BFS...
        stack<int>st;
        st.push(start);
        vector<int>arr;//to store final result..
        while(st.size())
        {
            int ele= st.top();
            //we are popping neigh after pushing it in stack once..
            if(!mp[ele].empty())
            {
                int neigh= mp[ele].back();
                mp[ele].pop_back();
                st.push(neigh);
            }
            //if we have nothing to push means we have reult stored in tack in reversed order..
            else
            {
                arr.push_back(ele);
                st.pop();
            }
        }
        vector<vector<int>> res;
        int n= arr.size();
        for(int i=n-1;i>0;i--)
        {
            res.push_back({arr[i],arr[i-1]});
        }
        return res;
    }
};