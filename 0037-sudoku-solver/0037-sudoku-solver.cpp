class Solution {
public:
    bool is_safe(vector<vector<char>>& board,int r,int c, char number)
    {
        for(int i=0;i<board.size();i++)
        {
            if(board[i][c] == number||board[r][i] == number )
            {
                return false;
            }
            int boxRow = 3 * (r / 3) + (i / 3);
            int boxCol = 3 * (c / 3) + (i % 3);
            if (board[boxRow][boxCol] == number)
            {   
                return false;
            }
        }
      

        return true;
    }
    bool solver(vector<vector<char>>& board, int r, int c)
    {
        if(c == board.size())
        {
            r+=1;
            c=0;
        }
        if(r ==  board.size())
        {
            return true;
        }
        if (board[r][c] != '.')
            return solver(board, r, c + 1);

        for(int i=1;i<=9;i++)
        {
            if(board[r][c] == '.' &&is_safe(board,r,c,static_cast<char>(i+'0') ) )
            {
                board[r][c]=static_cast<char>(i+'0');
                if(solver(board,r,c+1))
                {
                    return true;
                }   
               
                board[r][c]='.';   
            }
        }

        return false;

    }

    void solveSudoku(vector<vector<char>>& board) {
        solver(board,0,0);
    }
};