class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    //declare it as global
    map<int,int>mp;
    bool book(int start, int end) 
    {
        int sum=0;
        mp[start]++;
        mp[end]--;
        for(auto i:mp)
        {
            sum+= i.second;
            //triple booking
            if(sum>2)
            {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */