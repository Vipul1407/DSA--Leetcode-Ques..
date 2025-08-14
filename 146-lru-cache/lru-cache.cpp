class LRUCache {
public:
    struct node
    {
        public:
        node* next;
        node* prev;
        int key,val;
        node(int key,int val)
        {
            this->key= key;
            this->val=val;
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
    
    //adding node b/w head and head->next...
    void addnode(node* toadd)
    {
        node* temp= head->next;
        toadd->next= temp;
        toadd->prev= head;
        head->next= toadd;
        temp->prev= toadd;
    }
   
    //deleting node b/w todelete->next and todelete->prev
    //where todelete is the node to delete..
    void deletenode(node* todelete)
    {
        node *delprev= todelete->prev;
        node* delnext= todelete->next;
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