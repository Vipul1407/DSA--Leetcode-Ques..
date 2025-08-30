class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_map<char, int> check1;
        unordered_map<char, int> check2;
        unordered_map<char, int> check3;

        // Check each row 
        for (int row = 0; row < 9; row++) 
        {
            for (int col = 0; col < 9; col++) 
            {
                if (board[row][col] == '.')
                    continue;

                if (check1.count(board[row][col]))
                    return false;
                else
                    check1[board[row][col]]++;
            }
            check1.clear();
        }

        // Check each column
        for (int col = 0; col < 9; col++) 
        {
            for (int row = 0; row < 9; row++) 
            {
                if (board[row][col] == '.')
                    continue;

                if (check2.count(board[row][col]))
                    return false;
                else
                    check2[board[row][col]]++;
            }
            check2.clear();
        }

        // Check each 3x3 block
        for (int row = 0; row < 9; row += 3) 
        {
            for (int col = 0; col < 9; col += 3) 
            {
                // iterate through 3x3 block
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (board[row + i][col + j] == '.')
                            continue;

                        if (check3.count(board[row + i][col + j]))
                            return false;
                        else
                            check3[board[row + i][col + j]]++;
                    }
                }
                check3.clear();
            }
        }

        return true;
    }
};