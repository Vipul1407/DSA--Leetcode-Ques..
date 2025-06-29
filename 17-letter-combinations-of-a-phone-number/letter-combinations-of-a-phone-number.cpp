class Solution {
public:
    void solve(int i,string &digits,string curr,unordered_map<int,string>&mp,vector<string>&ans)
    {
        if(i>=digits.size())
        {
            if(curr!="")
                ans.push_back(curr);
            return;
        }
        
        int d= digits[i]-'0';
        for(auto ch: mp[d])
        {
            curr.push_back(ch);
            solve(i+1,digits,curr,mp,ans);
            curr.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) 
    {
        
        unordered_map<int,string>mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        
        string curr;
        vector<string>ans;
        solve(0,digits,curr,mp,ans);
        return ans;
    }
};