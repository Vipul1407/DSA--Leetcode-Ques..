class LRUCache {
public:
    class node
    {
        public:
        int key,val;
        node* prev;
        node* next;
        node(int key,int val)
        {
            this->key= key;
            this->val= val;
            prev=NULL;
            next=NULL;
        }
    };
    int cap;
    unordered_map<int,node*>mp;
    node* head= new node(-1,-1);
    node* tail= new node(-1,-1);

    LRUCache(int capacity) 
    {
        cap= capacity;
        head->next= tail;
        tail->prev= head;
    }
    
    void addnode(node* newnode)
    {
        node* temp= head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next= newnode;
        temp->prev= newnode;
    }

    void deletenode(node* delnode)
    {
        node* delprev= delnode->prev;
        node* delnext= delnode->next;
        delprev->next= delnext;
        delnext->prev= delprev;
    }

    int get(int key) 
    {
        if(mp.find(key)!=mp.end())
        {
            node* node= mp[key];
            int val= node->val;
            deletenode(node);
            mp.erase(key);
            addnode(node);
            mp[key]= head->next;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key)!=mp.end())
        {
            node* node= mp[key];
            mp.erase(key);
            deletenode(node);
        }
        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        mp[key]= head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */