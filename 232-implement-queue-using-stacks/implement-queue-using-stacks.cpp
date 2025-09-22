class MyQueue {
public:
    //METHOD-2
    //Using 1 stack..

    stack<int>st;
    MyQueue() {
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() 
    {
        //Using recursion..
        int x= st.top();
        st.pop();
        if(st.empty())
        {
            return x;
        }
        int y= pop();
        st.push(x);
        return y;
    }
    
    int peek() 
    {
        //Using recursion..
        int x= st.top();
        st.pop();
        if(st.empty())
        {
            st.push(x);
            return x;
        }
        int y= peek();
        st.push(x);
        return y;
    }
    
    bool empty() {
        return st.empty();
    }
};
/*
    class MyQueue {
    public:
    //METHOD-1
    //Using 2 stacks..

    stack<int>s1;
    stack<int>s2;
    MyQueue() {
    }
    
    void push(int x) 
    {
        //s1-->s2
        //push in s1
        //s2-->s1
        while(s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int val= s1.top();
        s1.pop();
        return val;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() { 
        return s1.empty();
    }
};
*/