class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    vector<pair<int,int>>events;
    vector<pair<int,int>>dbook;
    bool book(int s, int e) 
    {
        for(pair<int,int>p: dbook)
        {
            if(s<p.second && e>p.first)
            {
               return false;
            }
        }
        for(pair<int,int>&p: events)
        {
            if(s<p.second && e>p.first)
            {
                dbook.push_back({max(p.first,s),min(p.second,e)});
            }
        }
        events.push_back({s,e});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */