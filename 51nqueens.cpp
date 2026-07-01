class Solution {
public:

    void solver(int col,
    vector<vector<string>> &ans, vector<string> &board,
    vector<int> &leftrow, vector<int> &upperdiagonal, vector<int> &lowerdiagonal,
    int n){

        // Base Case: All columns are filled
        if(col == n){
            ans.push_back(board);
            return;
        }

        // Try placing a queen in every row of the current column
        for(int row = 0; row < n; row++){

            if(leftrow[row] == 0 &&
               upperdiagonal[(n - 1) + (col - row)] == 0 &&
               lowerdiagonal[row + col] == 0){

                // Choose
                board[row][col] = 'Q';
                leftrow[row] = 1;
                upperdiagonal[(n - 1) + (col - row)] = 1;
                lowerdiagonal[row + col] = 1;

                // Explore
                solver(col + 1, ans, board,
                       leftrow, upperdiagonal, lowerdiagonal, n);

                // Backtrack
                board[row][col] = '.';
                leftrow[row] = 0;
                upperdiagonal[(n - 1) + (col - row)] = 0;
                lowerdiagonal[row + col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> board(n);

        string s(n, '.');

        for(int i = 0; i < n; i++){
            board[i] = s;
        }

        vector<int> leftrow(n, 0);
        vector<int> upperdiagonal(2 * n - 1, 0);
        vector<int> lowerdiagonal(2 * n - 1, 0);

        solver(0, ans, board,
               leftrow, upperdiagonal, lowerdiagonal, n);

        return ans;
    }
};

/*
Pattern: Backtracking + Hashing

Summary:
- Place one queen in each column.
- Try every row in the current column.
- Use hash arrays to check row and diagonals in O(1).
- Place -> Recurse -> Backtrack.

Hash Arrays:
leftrow[row]
upperdiagonal[(n-1) + (col-row)]   // '\' diagonal
lowerdiagonal[row+col]             // '/' diagonal

TC: O(N!)
SC: O(N) (hash arrays + recursion stack, excluding output)
*/