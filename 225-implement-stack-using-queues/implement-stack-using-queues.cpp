//METHOD-2
//Using 1 queue..
class MyStack {
public:
    queue<int>q;
    MyStack() {
    }
    
    void push(int x) 
    {
        q.push(x);
        int n= q.size();
        for(int i=1;i<n;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val=q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/*
//METHOD-1
//Using 2 Queues..

class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) 
    {
        while(q1.size())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(q2.size())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int r= q1.front();
        q1.pop();
        return r;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
*/