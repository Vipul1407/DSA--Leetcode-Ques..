class MyCalendar {
public:
    MyCalendar() {
        
    }
    //declare it as global
    map<int,int>mp;
    bool book(int start, int end) 
    {
        mp[start]++;
        mp[end]--;
        int sum=0;
        for(auto i:mp)
        {
            sum+= i.second;
            if(sum>1)
            {
                //to not effect calculation of remaining elements
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */