#include <iostream>
using namespace std;

const int D = 20;
char board[D][D] = {};

void clearBoard(char mat[][D], int m, int n) {     //just initialising all with 0 (clearing)
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = '_';
        }
    }
}

void printMat(char mat[][D], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << mat[i][j]<<" ";
        }
        cout << endl;
    }
}

bool check(int n, int x, int y) {
    // check row or col
    for (int i = 0; i < n; ++i) {
        if (board[x][i] == 'Q') return false;       // checking the entire row (passed by user)

        if (board[i][y] == 'Q') return false;        // checking the entire column
    }

    // check diagonal
    for (int dist = 1; dist < n; ++dist) {
        int prRow = x - dist;
        int prCol = y - dist;
        if (prRow >= 0 && prRow <= n &&    // checking all elements along primary diagonal
            prCol >= 0 && prCol <= n &&
            board[prRow][prCol] == 'Q') {
            return false;
        }

        int secRow = x - dist;
        int secCol = y + dist;
        if (secRow >= 0 && secRow <= n &&      // checking all elements along seconddary diagonal
            secCol >= 0 && secCol <= n &&
            board[secRow][secCol] == 'Q') {
            return false;
        }
    }
    return true;
}

bool nqueen(int n, int r) {
    if (n == r) {
        // no row to place a queen
        // no queen to place( kaam ho chuka he to bahar aa jao)
        return true;
    }
    for (int c = 0; c < n; ++c) {
        bool canPlace = check(n, r, c);      // checking each cell of the entire row
        if (canPlace) {                       // if its empty place a queen(at the current cell)
            board[r][c] = 'Q';

            // checks if recursion is successful in setting the remaining board

            bool success = nqueen(n, r + 1);   // checking the next row by recursion (recursion apne aap check krega)
            if (success) {
                return true;                  // if its empty return true and repeat process
            }

            // backtracking

            board[r][c] = '_';           // if we can't palce a queen there remove the previously placed queen and place in
                                        // another cell of the initially passed row

        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    clearBoard(board, n, n);
    int success = nqueen(n, 0);  // starting form the first row jo ham krwa re he baki recursion se kra lege
    if (success) {
        printMat(board, n, n);
    }
    else {
        cout << "Failed";
    }
    return 0;

}