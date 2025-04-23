class Solution {
public:
    //METHOD-1
    //USING PRIORITY QUEUE..
    //TC= O(NLOGN)
    vector<int> rearrangeBarcodes(vector<int>& barcode) 
    {
        int n= barcode.size();
        vector<int>ans;
        //max heap.. storing freq, number 
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>mp;
        for(auto i:barcode)
        {
            mp[i]++;
        }
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        while(pq.size()>=2)
        {
            auto ele1= pq.top();
            pq.pop();
            auto ele2= pq.top();
            pq.pop();
            ans.push_back(ele1.second);
            ans.push_back(ele2.second);
            --ele1.first;
            --ele2.first;

            if(ele1.first>0)
            {
                pq.push(ele1);
            }
            if(ele2.first>0)
            {
                pq.push(ele2);
            }
        }
        if(!pq.empty())
        {
            ans.push_back(pq.top().second);
        }
        return ans;
    }
}; 