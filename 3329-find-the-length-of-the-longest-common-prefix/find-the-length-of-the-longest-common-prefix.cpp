
struct trienode
{
    //char d;
    //bool isterminal;
    trienode* children[10];
};

class Solution 
{
public:
    trienode* trie()
    {
        trienode* node= new trienode();
        for(int i=0;i<10;i++)
        {
            node->children[i]=NULL;
        }
        return node;
    };
    void insert(int num, trienode* root)
    {
        trienode* child= root;
        string str= to_string(num);
        for(auto ch:str)
        {
            int idx= ch-'0';
            if(child->children[idx]==NULL)
            {
                child->children[idx]= trie(); 
            }
            child= child->children[idx];
        }
    }
    int search(int num, trienode* root)
    {
        trienode* child= root;
        string str= to_string(num);
        int len=0;
        for(auto ch:str)
        {
            int idx= ch-'0';
            if(child->children[idx])
            {
                len++;
                child= child->children[idx];
            }
            else
            {
                break;
            }
        }
        return len;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2)
    {
        trienode* root= trie();
        for(auto i:arr1)
        {
            insert(i,root);
        }
        int res=0;
        for(auto i:arr2)
        {
            res= max(res,search(i,root));
        }
        return res;
    }
};