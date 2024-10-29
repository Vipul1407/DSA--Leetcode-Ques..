class Solution {
public:
    int findMinDifference(vector<string>& time) 
    {
        vector<int>arr;
        for(auto ele:time)
        {
            int hr= stoi(ele.substr(0,2));
            int min= stoi(ele.substr(3));
            int total= hr*60+min;
            arr.push_back(total);
        }
        sort(arr.begin(),arr.end());
        int diff=1440;
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            diff= min(diff,arr[i]-arr[i-1]);
        }
        //24:00=  1440 min--> will see the diff of last element in arr..
        //==> 1440-arr[n-1] becoz it is clockwise
        //00:00=  0 min-----> will see the diff from first element in arr..
        //==> arr[0]-0 becoz it is anticlockwise
        //adding both of them might be the possible ans..
        return min(diff, 1440-arr[n-1]+arr[0]);
    }
};