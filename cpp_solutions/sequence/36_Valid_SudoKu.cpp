/*

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

*/


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used[9];     
        for(int i=0; i<9; i++ )
        {
            // check row
            fill(used, used + 9, false);
            for(int j=0; j< 9; j++)
            {
                if(!validate(used, board[i][j])) return false;
            }
            
             // check column
            fill(used, used + 9, false);
            for(int j=0; j< 9; j++)
            {
                if(!validate(used, board[j][i])) return false;
            }
        }
      
        // check 3x3 block      
        for(int i=0; i< 3; i++)
        {
            for(int j=0; j< 3; j++)
            {
                fill(used, used + 9, false);
                for(int r=0; r<3; r++)
                {
                    for(int c=0; c<3;c++)
                    {
                       if(!validate(used, board[i*3+r][j*3+c])) return false;
                    }
                }
            }
        }
        
        return true;
    }
private:
    bool validate(bool used[9], char ch)
    {
        if (ch == '.') return true;
        if (used[ch - '1']) return false;
        return used[ch - '1'] = true;
    }
};