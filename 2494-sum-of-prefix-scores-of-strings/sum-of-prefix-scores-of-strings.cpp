// Approach 2-> Using Trie with initialization

// TC= O(N*d) where d -> avg length of each word..
// SC= O(N*d)

struct TrieNode{
   int cnt;
   TrieNode* children[26];
   TrieNode(){
      cnt= 0;
      for(int i=0; i<26; i++){
         children[i]= NULL;
      }
   }
};

class Solution {
public:

    void insert(string word, TrieNode* root)
    {
        for(char ch: word)
         {
            int index= ch-'a';
            if(!root->children[index])
            {
                root->children[index]= new TrieNode();
            }
            
            // move forward....
            root= root->children[index];
            root->cnt+= 1;
         }
    }

    int getScores(string word, TrieNode* root)
    {
        int count= 0;
        for(char ch: word)
        {
            int index= ch-'a';
        
            // move forward...
            root= root->children[index];
            count+= root->cnt;
        }
       return count; 
    }


    vector<int> sumPrefixScores(vector<string>& words) {
        int n= words.size();
        
        TrieNode* root= new TrieNode();
        for(int i=0; i<n; i++)
        {
           insert(words[i],root);
        }
        
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
           ans[i]= getScores(words[i],root);
        }
       return ans; 
    }
};












// Approach 1-> Using Trie with separate func for initialization

// TC= O(N*d) where d -> avg length of each word..
// SC= O(N*d)

/*

struct TrieNode{
   int cnt;
   TrieNode* children[26];
};

class Solution {
public:
    
    TrieNode* formTrieNode()
    {
        TrieNode* root= new TrieNode();
        for(int i=0; i<26; i++)
        {
            root->children[i]= NULL;
        }
        root->cnt= 0;
        return root;
    }

    void insert(string word, TrieNode* root)
    {
        for(char ch: word)
         {
            int index= ch-'a';
            if(!root->children[index])
            {
                root->children[index]= formTrieNode();
            }
            
            // move forward....
            root= root->children[index];
            root->cnt+= 1;
         }
    }

    int getScores(string word, TrieNode* root)
    {
        int count= 0;
        for(char ch: word)
        {
            int index= ch-'a';
        
            // move forward...
            root= root->children[index];
            count+= root->cnt;
        }
       return count; 
    }


    vector<int> sumPrefixScores(vector<string>& words) {
        int n= words.size();
        
        TrieNode* root= new TrieNode();
        for(int i=0; i<n; i++)
        {
           insert(words[i],root);
        }
        
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
           ans[i]= getScores(words[i],root);
        }
       return ans; 
    }
};

*/