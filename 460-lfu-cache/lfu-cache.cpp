struct node
{
    public:
    int key,val,cnt;
    node* prev;
    node* next;
    node(int key,int val)
    {
        this->key= key;
        this->val= val;
        cnt=1; 
    }
};
struct listt
{
    int size;
    node* head;
    node* tail;
    listt()
    {
        head= new node(0,0);
        tail= new node(0,0);
        head->next= tail;
        tail->prev= head;
        size=0;
    }

    void addnode(node* newnode)
    {
        node* temp= head->next;
        newnode->next= temp;
        newnode->prev= head;
        head->next= newnode;
        temp->prev= newnode;
        size++;
    }

    void deletenode(node* delnode)
    {
        node* delprev= delnode->prev;
        node* delnext= delnode->next;
        delprev->next= delnext;
        delnext->prev= delprev;
        size--;
    }
};

class LFUCache 
{
    unordered_map<int,node*>keymp;
    unordered_map<int,listt*>listmp;

    //cache..
    int maxsize;
    int minfreq;
    int currsize;

    public:

    LFUCache(int capacity) 
    {
        maxsize= capacity;
        minfreq= 0;
        currsize= 0;
    }
    
    void updatefreq(node* node)
    {
        keymp.erase(node->key);
        listmp[node->cnt]->deletenode(node);
        if(node->cnt==minfreq && listmp[node->cnt]->size==0)
        {
            minfreq++;
        }
        listt* nexthighfreq= new listt();
        if(listmp.find(node->cnt+1)!=listmp.end())
        {
            nexthighfreq= listmp[node->cnt+1];
        }
        node->cnt+=1;
        nexthighfreq->addnode(node);
        listmp[node->cnt]= nexthighfreq;
        keymp[node->key]= node;
    }

    int get(int key) 
    {
        if(keymp.find(key)!=keymp.end())
        {
            node* node= keymp[key];
            int val= node->val;
            updatefreq(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(maxsize==0)
        {
            return;
        }
        if(keymp.find(key)!=keymp.end())
        {
            node* node= keymp[key];
            node->val= value;
            updatefreq(node);
        }
        else
        {
            if(currsize==maxsize)
            {
                listt* listt= listmp[minfreq];
                keymp.erase(listt->tail->prev->key);
                listmp[minfreq]->deletenode(listt->tail->prev);
                currsize--;
            }
            currsize++;
            minfreq=1;
            listt* listfreq= new listt();
            if(listmp.find(minfreq)!=listmp.end())
            {
                listfreq= listmp[minfreq];
            }
            node* newnode= new node(key,value);
            listfreq->addnode(newnode);
            keymp[key]= newnode;
            listmp[minfreq]= listfreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */