// Tic Tac Toe game
// Khyle Mott


#include <iostream>
#include <string>
using namespace std;

//	constants
const char x = 'X';
const char o = 'O';
const char Open = ' ';



//	variables
char board[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char piece1 = x;
char piece2 = o;
char player;
string name1;
string name2;
string person1;
string person2;
int a;
int n;

//	Function declarations
void SetBoard();
void IdentifyPiece();
void Input();


void SetBoard() { 								// Sets up the board and displays it
	cout << "----------- " << endl;
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			cout << board[r][c] << " | ";
		}
		cout << endl;
		cout << "----------- " << endl;
	}
}

void IdentifyPlayer()							// Asks the name of the players and accepts the user input
{
	cout << "Type in the name of player 1 without spaces: " << endl;
	cin >> name1;
	cout << "Type in the name of player 2 without spaces: " << endl;
	cin >> name2;
}

void Input()								// Instructs the user to place their piece on the board, and checks for invalid moves
{	cout << person1 << " type in the number on the board you'd wish to use: ";
	cin >> a;

	a--;
	if (board[a / 3][a % 3] != x && board[a / 3][a % 3] != o)
	{
		board[a / 3][a % 3] = player;
	}
	else {
		cout << "You can't make that move!" << endl;
	}
}



void PlayerToggle()							// Toggles between who's turn it is
{
	if (player == piece1)
	{
		player = piece2;
	}
	else {
		player = piece1;
	}
	if (person1 == name1)
	{
		person1 = name2;
	}
	else {
		person1 = name1;
	}	
	}

void IdentifyPiece()						// Allows the players to choose X or O
{
	cout << "What piece does player 1 want to use (X-x's, O-o's)? ";
	cin >> piece1;
	piece1 = toupper(piece1);
	if (piece1 != x) {
		piece1 = o;
	}
	else {
		piece1 = x;
	}
	cout << "What piece does player 2 want to use (X-x's, O-o's)? ";
	cin >> piece2;
	piece2 = toupper(piece2);
	if (piece2 != x) {
		piece2 = o;
	}
	else {
		piece2 = x;
	}
}

char Winner()								// Determine who wins the game or if it ends in a draw
{
	//	first player
	if (board[0][0] == x && board[0][1] == x && board[0][2] == x) {
		return x;
	}
	if (board[1][0] == x && board[1][1] == x && board[1][2] == x) {
		return x;
	}
	if (board[2][0] == x && board[2][1] == x && board[2][2] == x) {
		return x;
	}
	if (board[0][0] == x && board[1][0] == x && board[2][0] == x) {
		return x;
	}
	if (board[0][1] == x && board[1][1] == x && board[2][1] == x) {
		return x;
	}
	if (board[0][2] == x && board[1][2] == x && board[2][2] == x) {
		return x;
	}
	if (board[0][0] == x && board[1][1] == x && board[2][2] == x) {
		return x;
	}
	if (board[2][0] == x && board[1][1] == x && board[0][2] == x) {
		return x;
	}
	//	second player
	if (board[0][0] == o && board[0][1] == o && board[0][2] == o) {
		return o;
	}
	if (board[1][0] == o && board[1][1] == o && board[1][2] == o) {
		return o;
	}
	if (board[2][0] == o && board[2][1] == o && board[2][2] == o) {
		return o;
	}
	if (board[0][0] == o && board[1][0] == o && board[2][0] == o) {
		return o;
	}
	if (board[0][1] == o && board[1][1] == o && board[2][1] == o) {
		return o;
	}
	if (board[0][2] == o && board[1][2] == o && board[2][2] == o) {
		return o;
	}
	if (board[0][0] == o && board[1][1] == o && board[2][2] == o) {
		return o;
	}
	if (board[2][0] == o && board[1][1] == o && board[0][2] == o) {
		return o;
	}

	return '/';

}

int main()							// The main function
{		
	cout << "Khyle's Tic Tac Toe Game!" << endl;
	cout << " " << endl;
	IdentifyPlayer();
	IdentifyPiece();
	PlayerToggle();
	SetBoard();
	while (1) {
		n++;
		Input();
		SetBoard();
		if (Winner() == x)
		{
			cout << name1 <<" has won the game!" << endl;
			break;
		}
		else if (Winner() == o)
		{
			cout << name2 << " has won the game!" << endl;
			break;
		}
		else if (Winner() == '/' && n == 9)
		{
			cout << "The game has ended in a draw!" << endl;
			break;
		}
		PlayerToggle();
	}
    return 0;
}


