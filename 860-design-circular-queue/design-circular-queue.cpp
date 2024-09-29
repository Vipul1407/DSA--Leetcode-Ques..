class MyCircularQueue {
public:
    vector<int>que;//circular queue implemented by vector/array
    int k;//max size
    int size=0;//curr size
    int r,f;//rear and front index 
    MyCircularQueue(int k) 
    {
        this->k=k;  
        que= vector<int>(k,0); 
        f=0;
        r=0;
    }
    
    bool enQueue(int value) 
    {
        if(size==k)
        {
            return false;
        }
        if(size==0)
        {
            f=r=0;
            que[f]=value;
            size++;
            return true;
        }
        else
        {
            f= (f+1)%k;
            que[f]= value;
            size++;
            return true;
        }
    }
    
    bool deQueue() 
    {
        if(size==0)
        {
            return false;
        }
        else
        {
            que[r]=0;
            r= (r+1)%k;
            size--;
            return true;
        }
    }
    
    int Front() 
    {
        if(size==0)
        {
            return -1;
        }
        else
        {
            return que[r];
        }
    }
    
    int Rear() 
    {
        if(size==0)
        {
            return -1;
        }
        else
        {
            return que[f];
        }
    }
    
    bool isEmpty() 
    {
        return size==0;
    }
    
    bool isFull() 
    {
        return size==k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */