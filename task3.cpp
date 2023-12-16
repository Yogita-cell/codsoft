#include <iostream>
#include <vector>

class TicTacToe {
private:
std::vector<std::vector<char>> board;
char currentPlayer;

public:
TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

void displayBoard() const {
for (const auto& row : board) {
for (char cell : row) {
std::cout << cell << " | ";
}
std::cout << "\n---------\n";
}
}

void switchPlayer() {
currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool isMoveValid(int row, int col) const {
return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

bool checkWin() const {
// Check rows, columns, and diagonals
for (int i = 0; i < 3; ++i) {
if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
return true; // Row win
}
if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
return true; // Column win
}
}
if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
return true; // Diagonal win (top-left to bottom-right)
}
if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
return true; // Diagonal win (top-right to bottom-left)
}
return false;
}

bool isBoardFull() const {
for (const auto& row : board) {
for (char cell : row) {
if (cell == ' ') {
return false; // Board is not full
}
}
}
return true; // Board is full (draw)
}

void playGame() {
int row, col;
while (true) {
displayBoard();
std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
std::cin >> row >> col;

if (isMoveValid(row, col)) {
board[row][col] = currentPlayer;

if (checkWin()) {
displayBoard();
std::cout << "Player " << currentPlayer << " wins!\n";
break;
} else if (isBoardFull()) {
displayBoard();
std::cout << "It's a draw!\n";
break;
}

switchPlayer();
} else {
std::cout << "Invalid move. Try again.\n";
}
}
}
};

int main() {
char playAgain;
do {
TicTacToe game;
game.playGame();

std::cout << "Do you want to play again? (y/n): ";
std::cin >> playAgain;

} while (playAgain == 'y' || playAgain == 'Y');

return 0;
}

  