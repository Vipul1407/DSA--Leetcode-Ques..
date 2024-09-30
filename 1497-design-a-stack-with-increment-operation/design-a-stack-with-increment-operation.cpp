class CustomStack {
public:
    vector<int>st;
    int size=0;
    int k;
    CustomStack(int k) 
    {
        this->k=k;    
    }
    
    void push(int x) 
    {
        if(size==k)
        {
            return;
        }
        st.push_back(x);
        size++;
    }
    
    int pop() 
    {
        if(size==0)
        {
            return -1;
        }
        else
        {
            int temp= st.back();
            st.pop_back();
            size--;
            return temp;
        }
    }
    
    void increment(int no, int val) 
    {
        int q= min(no,size);
        for(int i=0;i<q;i++)
        {
            st[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */