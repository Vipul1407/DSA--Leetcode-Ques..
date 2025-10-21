class Solution {
public:
    //METHOD-1
    //BFS..
    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        unordered_set<string>st(begin(bank),end(bank));
        unordered_set<string>vis;
        if(!st.count(endGene))
        {
            return -1;
        }
        queue<pair<string,int>>q;
        q.push({startGene,0});
        vis.insert(startGene);
        int ans= INT_MAX;
        string possible="ACGT";
        while(q.size())
        {
            int n= q.size();
            while(n--)
            {
                string curr= q.front().first;
                int cnt= q.front().second;
                if(curr==endGene)
                {
                    ans= min(ans,cnt);
                }
                q.pop();
                for(int i=0;i<curr.size();i++)
                {
                    string temp= curr;
                    for(auto j:possible)
                    {
                        temp[i]= j;
                        if(st.count(temp) && !vis.count(temp))
                        {
                            q.push({temp,cnt+1});
                            vis.insert(temp);
                        }
                    }
                }
            }
        }
        return ans==INT_MAX? -1:ans;
    }
};