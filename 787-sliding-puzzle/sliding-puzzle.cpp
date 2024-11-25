class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) 
    {
        string str="";
        for(auto i:board)
        {
            for(auto j:i)
            {
                str+= j+'0';
            }
        }
        string tar="123450";
        unordered_map<int,vector<int>>mp;
        mp[0]={1,3};
        mp[1]={0,2,4};
        mp[2]={1,5};
        mp[3]={0,4};
        mp[4]={1,3,5};
        mp[5]={2,4};   
        queue<string>q;
        unordered_set<string>vis;
        q.push(str);
        vis.insert(str);
        int level=0;
        while(!q.empty())
        {
            int n= q.size();
            while(n--)
            {
                string curr= q.front();
                q.pop();
                if(curr==tar)
                {
                    return level;
                }
                int idx0= curr.find('0');
                for(auto i:mp[idx0])
                {
                    string newstr= curr;
                    swap(newstr[idx0],newstr[i]);
                    if(vis.find(newstr)==vis.end())
                    {
                        q.push(newstr);
                        vis.insert(newstr);
                    }
                }
            }
            level++;
        }
        return -1;
    }
}; 