#include <iostream>
#include <iomanip>
using namespace std;
const int D = 20;
int board[D][D] = {};

void clearBoard(int mat[][D], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] =0;
        }
    }
}

void printMat(int mat[][D], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(3) << mat[i][j] << " ";
        }
        cout << endl;
    }
}

bool check(int n, int x, int y){
    return (x >= 0 && x < n &&
            y >= 0 && y < n &&
            board[x][y] == 0);     // it will directly return true or false
}

bool knightMove(int n, int x, int y, int moveNo) {
    if (moveNo == n * n) {   //max move in a nxn is nxn-1
        return true; // kaam ho chuka he
    }

    // storing the direction in which it can move
    int rowDir[] = { +1, +2, +2, +1, -1, -2, -2, -1};    // along row
    int colDir[] = { +2, +1, -1, -2, -2, -1, +1, +2};   // along column

    for (int i = 0; i < 8; ++i) {              // max 8 moves are there
        int nextRow = x + rowDir[i];   // making it move the "dhai" chaal
        int nextCol = y + colDir[i];
        bool canPlace = check(n, nextRow, nextCol);
        if (canPlace) {                                     // if it can go there put the move no there
            board[nextRow][nextCol] = moveNo;
            bool success = knightMove(n, nextRow, nextCol, moveNo + 1);
            if (success) return true;
            else
             board[nextRow][nextCol] = 0;           // if we can't backtrack to the previous correct position
        }
    }
    return false;
}


int main() {
    int n;
    cin >> n;

    board[0][0] = -1;

   // clearBoard(board,n,n);
    bool success = knightMove(n, 0, 0, 1);
    if (success) {
        printMat(board, n, n);
    }
    else {
        cout << "Failed";
    }
    return 0;
}