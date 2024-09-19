class Solution {
public:
    vector<int>solve(string exp)
    {
        //storing string as key with its vector<int> so to avoid redundant calculations..
        unordered_map<string,vector<int>>mp;
        if(mp.find(exp)!=mp.end())
        {
            return mp[exp];
        }
        vector<int>ans;
        for(int i=0;i<exp.length();i++)
        {
            if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*')
            {
                vector<int>left= solve(exp.substr(0,i));
                vector<int>right= solve(exp.substr(i+1));
                for(auto &x: left)
                {
                    for(auto &y: right)
                    {
                        if(exp[i]=='+')
                        {
                            ans.push_back(x+y);
                        }
                        else if(exp[i]=='-')
                        {
                            ans.push_back(x-y);
                        }
                        //(exp[i]=='*')
                        else 
                        {
                            ans.push_back(x*y);
                        }
                    }
                }
            }
        }
        //if we have input as 21 only then we have to directly return this in array
        if(ans.empty())
        {
            ans.push_back(stoi(exp));
        }
        //return ans after storing it in mp..
        return mp[exp]= ans;
    }
    vector<int> diffWaysToCompute(string exp) 
    {
        return solve(exp);
    }
};   