// Using Floyd Warshall 

// TC= O(26^3)+ O(2* N)
// SC= O(N^2)

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost)
    {
        int n= original.size();

        // create adj matrix...
        vector<vector<long long>> adjMatrix(26, vector<long long> (26, INT_MAX));

        for(int i=0; i<26; i++)
        {
            adjMatrix[i][i]= 0;
        }

        for(int i=0; i<n; i++)
        {   
            char ch1= original[i];
            char ch2= changed[i];
    
            adjMatrix[ch1-'a'][ch2-'a']= min((long long) cost[i], adjMatrix[ch1-'a'][ch2-'a']);
        }
        
        // Initializing min cost... 
        for(int k=0; k<26; k++)
        {
            for(int i=0; i<26; i++)
            {
                for(int j=0; j<26; j++)
                {
                    if(adjMatrix[i][k]== INT_MAX || adjMatrix[k][j]== INT_MAX)
                    {
                        continue;
                    }
                adjMatrix[i][j]= min(adjMatrix[i][j], adjMatrix[i][k]+adjMatrix[k][j]);
                }
            }
        }
        
        long long totalCost= 0;
        for(int i=0; i<source.size(); i++)
        {
            if(source[i] != target[i])
            {
               long long currCost= adjMatrix[source[i]-'a'][target[i]- 'a'];
               if(currCost== INT_MAX)
               {
                return -1;
                } 
            totalCost+= currCost;
            }
        }

    return totalCost;
    }
};