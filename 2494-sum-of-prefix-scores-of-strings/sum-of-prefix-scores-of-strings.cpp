struct trienode{
    //char d;
    //bool isterminal;
    int cnt=0;//to count prefix/length
    trienode* children[26];//containing only lowercase 
};
class Solution 
{
public:
    trienode* trie()
    {
        trienode* node= new trienode();
        for(int i=0;i<26;i++)
        {
            node->children[i]= NULL;
        }
        node->cnt=0;
        return node;
    }
    void insert(string str,trienode*root)
    {
        trienode* child= root;
        for(auto ch:str)
        {
            int idx= ch-'a';
            if(child->children[idx]==NULL)
            {
                child->children[idx]= trie();
            }
            child= child->children[idx];
            child->cnt+=1;// Increment after moving to the correct child node
        }
    }
    int calc(string str, trienode*root)
    {
        trienode*child= root;
        int ans=0;
        for(auto ch:str)
        {
            int idx= ch-'a';
            child= child->children[idx];
            ans+= child->cnt;//add cnt to ans after moving to correct child
        }
        return ans;
    }
    //we have to count all prefixes of that number
    vector<int> sumPrefixScores(vector<string>& words) 
    {
        trienode* root= trie();
        for(auto i:words)
        {
            insert(i,root);
        }
        int n= words.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i]=calc(words[i],root);
        }
        return ans;
    }
};