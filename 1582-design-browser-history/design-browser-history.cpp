class node
{
    public:
    node* next;
    node* prev;
    string d;
    node(string d)
    {
        this->d=d;
        next= prev= NULL;
    }
    node(string d, node* next, node* prev)
    {
        this->d=d;
        this->next= next;
        this->prev= prev;
    }
};

class BrowserHistory {
public:
    node* curr;
    BrowserHistory(string homepage) 
    {
        curr= new node(homepage);
    }
    
    void visit(string url) 
    {
        node* newnode= new node(url);
        curr->next= newnode;
        newnode->prev= curr;
        curr= newnode;
    }
    
    string back(int steps) 
    {
        while(steps--)
        {
            if(curr->prev)
            {
                curr= curr->prev;
            }
            else
            {
                break;
            }
        }
        return curr->d;
    }
    
    string forward(int steps) 
    {
        while(steps--)
        {
            if(curr->next)
            {
                curr= curr->next;
            }
            else
            {
                break;
            }
        }
        return curr->d;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */