#include <iostream>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
      return true;
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
      return true;
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    return true;
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    return true;
  return false;
}

int main() {
  char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  char currentPlayer = 'X';
  int row, col;

  while (true) {

    do {
      // Display the current state of the board
      displayBoard(board);

      // Get the current player's move
      cout << "Player " << currentPlayer << ", enter your move (row column): ";
      cin >> row >> col;

      // Check if the move is valid and update the board
      if (row >= 0 && row < 3 && col >= 0 && col < 3 &&
          board[row][col] == ' ') {
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
          displayBoard(board);
          cout << "Player " << currentPlayer << " wins!" << endl;
          break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
      } else {
        cout << "Invalid move. Try again." << endl;
      }

      // Check for a draw
      bool isDraw = true;
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (board[i][j] == ' ') {
            isDraw = false;
            break;
          }
        }
        if (!isDraw)
          break;
      }
      if (isDraw) {
        displayBoard(board);
        cout << "It's a draw!" << endl;
        break;
      }
    } while (true);

    int x;
    cout << "Press 1 to Play Again  \n";
    cout << "Press 0 to Quit \n";
    cin >> x;

    if (x == 0) {
      break;
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        board[i][j] = ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
