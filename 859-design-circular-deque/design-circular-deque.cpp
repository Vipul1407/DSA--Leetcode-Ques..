class MyCircularDeque 
{
public:

    int size=0;//to track curr size of deque
    int f;//to track front
    int r;//to track rear
    int k;//to store max size of deque
    vector<int>deq;//implemented using circular array/vector

    MyCircularDeque(int k)
    {
        deq= vector<int>(k,0);
        this->k=k;
        f=0;
        r=k-1;
    }
    
    bool insertFront(int value) 
    {
        if(size==k)
        {
            return false;
        }
        else
        {
            f= (f-1+k)%k;//front me insert krne k liye f--
            deq[f]=value;
            size++;
            return true;
        }       
    }
    
    bool insertLast(int value) 
    {
        if(size==k)
        {
            return false;
        }
        else
        {
            r= (r+1)%k;//last me insert krne k liye r++
            deq[r]=value;
            size++;
            return true;
        }
    }
    
    bool deleteFront() 
    {
        if(size==0)
        {
            return false;
        }
        else
        {
            deq[f]=0;
            size--;
            f= (f+1)%k;// here we will do +1 not -1
            return true;
        }
    }
    
    bool deleteLast() 
    {
        if(size==0)
        {
            return false;
        }
        else
        {
            deq[r]=0;
            r= (r-1+k)%k;// here do -1 not +1
            size--;
            return true;
        }
    }
    
    int getFront() 
    {
        if(size==0)
        {
            return -1;
        }
        return deq[f];
    }
    
    int getRear() 
    {
        if(size==0)
        {
            return -1;
        }
        return deq[r];
    }
    
    bool isEmpty() 
    {
        if(size==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool isFull() 
    {
        if(size==k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */