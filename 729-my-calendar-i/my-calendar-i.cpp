class MyCalendar {
public:
    MyCalendar() {
        
    }
    vector<pair<int,int>>vec;
    bool book(int s, int e) 
    {
        for(pair<int,int>p: vec)
        {
            if(s<p.second && e>p.first)
            {
                return false;
            }
        }
        vec.push_back({s,e});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */