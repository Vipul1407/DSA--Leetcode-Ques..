// class Solution {
// public:
//     int countCoveredBuildings(int n, vector<vector<int>>& buildings) 
//     {
//         set<pair<int,int>>st;
//         for(auto i:buildings)
//         {
//             st.insert({i[0],i[1]});
//         }
//         int cnt=0;
//         for(auto &b: buildings)
//             {
//                 int x= b[0];
//                 int y= b[1];
//                 int all4= 0;
//                 for(int i=1;i<x;i++)
//                     {
//                         if(st.count({i,y}))
//                         {
//                             all4++;
//                             break;
//                         }
//                     }
//                 for(int i=x+1;i<n+1;i++)
//                     {
//                         if(st.count({i,y}))
//                         {
//                             all4++;

//                             break;
//                         }
//                     }
//                 for(int i=1;i<y;i++)
//                     {
//                         if(st.count({x,i}))
//                         {
//                             all4++;
//                             break;
//                         }
//                     }
//                 for(int i=y+1;i<n+1;i++)
//                     {
//                         if(st.count({x,i}))
//                         {
//                             all4++;
//                             break;
//                         }
//                     }
//                 if(all4==4)
//                 {
//                     cnt++;
//                 }
//             }
//         return cnt;
//     }
// };

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) 
    {
        unordered_map<int, vector<int>> row, col;
        
        for(auto &b : buildings)
        {
            row[b[0]].push_back(b[1]);
            col[b[1]].push_back(b[0]);
        }
        
        // Sort all row and column lists
        for(auto &[r, v] : row) sort(v.begin(), v.end());
        for(auto &[c, v] : col) sort(v.begin(), v.end());
        
        int cnt = 0;
        for(auto &b : buildings)
        {
            int x = b[0];
            int y = b[1];
            
            // check left (y-1), right (y+1) in row[x]
            auto it = lower_bound(row[x].begin(), row[x].end(), y);
            bool hasLeft = (it != row[x].begin());
            bool hasRight = (it != row[x].end() && next(it) != row[x].end());
            
            // check up (x-1), down (x+1) in col[y]
            it = lower_bound(col[y].begin(), col[y].end(), x);
            bool hasUp = (it != col[y].begin());
            bool hasDown = (it != col[y].end() && next(it) != col[y].end());
            
            if(hasLeft && hasRight && hasUp && hasDown)
                cnt++;
        }
        
        return cnt;
    }
};
