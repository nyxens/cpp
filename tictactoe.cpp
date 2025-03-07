#include <iostream>
using namespace std;
#define N 3
void startboard(char board[N][N]) 
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            board[i][j] = ' ';
        }
    }
}
void showboard(char board[N][N]) 
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cout << board[i][j];
            if (j < N - 1) cout << " | ";
        }
        cout << endl;
        if (i < N - 1) cout << "--|---|--" << endl;
    }
}
bool checkWin(char board[N][N], char player) 
{
    for (int i = 0; i < N; i++) 
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) 
        {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) 
        {
        return true;
        }
    return false;
}
bool isDraw(char board[N][N]) 
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}
int main() 
{
    char board[N][N];
    char player = 'X';
    int row, col;
    startboard(board);

    cout << "Welcome to Tic Tac Toe!\n";
    showboard(board);

    while (true) 
    {
        cout << "Player " << player << ", enter your move (row and column): ";
        cin >> row >> col;
        if (row < 0 || row >= N || col < 0 || col >= N || board[row][col] != ' ') 
        {
            cout << "Invalid move! Try again.\n";
            continue;
        }
        board[row][col] = player;
        showboard(board);
        if (checkWin(board, player)) 
        {
            cout << "Player " << player << " wins!\n";
            break;
        }
        if (isDraw(board)) 
        {
            cout << "It's a draw!\n";
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    return 0;
}
