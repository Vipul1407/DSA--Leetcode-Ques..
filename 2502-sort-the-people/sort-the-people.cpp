class Solution {
public:
    vector<string> sortPeople(vector<string>& name, vector<int>& ht) 
    {
        vector<pair<int,string>>vec;
        int n= ht.size();
        for(int i=0;i<n;i++)
        {
            vec.push_back({ht[i],name[i]});
        }
        sort(vec.rbegin(),vec.rend());
        for(int i=0;i<n;i++)
        {
            name[i]= vec[i].second;
        }
        return name;
    }
};