
class Solution
{
public:
    bool is_safe(vector<string> &board, int n, int col, int r)
    {

        for (int i = 0; i < r; i++)
        {
            if (board[i][col] == 'Q')
                return false;
        }

        for (int i = r - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        for (int i = r - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void nqueens(vector<vector<string>> &ans, vector<string> &board, int r, int n)
    {

        if (r == n)
        {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (is_safe(board, n, col, r))
            {
                board[r][col] = 'Q';
                nqueens(ans, board, r + 1, n);
                board[r][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.')); // i am kind of intialsing with . . . . . .  saw it from google 

        nqueens(ans, board, 0, n);
        return ans;
    }
};