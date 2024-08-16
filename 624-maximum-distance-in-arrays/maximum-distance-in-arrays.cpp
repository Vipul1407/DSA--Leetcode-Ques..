class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int n = arrays.size();
        // min heap.. storing value, array index(to track which list)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqmin;
        // max heap...
        priority_queue<pair<int, int>> pqmax;
        for (int i = 0; i < n; i++)
        {
            pqmin.push({arrays[i].front(), i});
            pqmax.push({arrays[i].back(), i});
        }
        auto [minval, minidx]= pqmin.top();
        pqmin.pop();
        auto [maxval, maxidx]= pqmax.top();
        pqmax.pop();
        int diff= abs(maxval-minval);

        //if both are form same array..
        if(minidx == maxidx)
        {
            int d1= abs(pqmax.top().first- minval);
            int d2= abs(maxval-pqmin.top().first);
            diff= max(d1,d2);
        }
        return diff;
    }
};