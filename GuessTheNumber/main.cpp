#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>

// Game numbers generator + console animation
short int generateNumber(short int game_difficultyLevel) {
	using std::cout;

	// Number generator
	short int randomNumber = 0;

	srand(time(0));

	switch(game_difficultyLevel) {
		case 1:
			randomNumber = rand() % 10;
			break;
		case 2:
			randomNumber = rand() % 50;
			break;
		case 3:
			randomNumber = rand() % 100;
			break;
	}

	// Console animation
	cout << "Generating number:\n";
	for (int i = 0; i < 15; i++) {
		Sleep(150);
		switch (game_difficultyLevel) {
		case 1:
			cout << "\r" << rand() % 10;
			break;
		case 2:
			cout << "\r" << rand() % 50;
			break;
		case 3:
			cout << "\r" << rand() % 100;
			break;
		}
	}
	system("cls");

	return randomNumber;
}

// Game Core
void gameStart(short int game_difficultyLevel) {
	using std::cout;
	using std::cin;

	system("cls");
	
	// Set player lives
	short int playerLives = 3;
	switch(game_difficultyLevel) {
		case 1:
			playerLives = 5;
			break;
		case 2:
			playerLives = 3;
			break;
		case 3:
			playerLives = 1;
			break;
	}

	// Start player guessing
	short int randomNumber;
	short int playerAnswer;
	short int playerPoints = 0;

	while(playerLives != 0) {
		randomNumber = generateNumber(game_difficultyLevel);

		cout << "Lives: " << playerLives << "\n\n";

		cout << "What number am I thinking about now?\n";

		while(playerLives != 0) {
			cout << "Enter the answer: ";
			cin >> playerAnswer;

			if(playerAnswer == randomNumber) {
				playerPoints++;

				system("cls");
				cout << "You guessed, congratulations! Score: " << playerPoints << "\n\n";

				break;
			}
			else {
				playerLives--;

				system("cls");
				cout << "Wrong answer, try again! Lives: " << playerLives << "\n\n";

				cout << "What number am I thinking about now?\n";
			}
		}
	}

	// Player game over
	system("cls");
	cout << "Game Over!\n";
	cout << "Your score: " << playerPoints << "\n";
}

// Game Menu
int main() {
	using std::cout;
	using std::cin;

	cout << "Guess The Number\n";
	cout << "A simple game where the player must guess a number given by the computer.\n\n";

	cout << "Choose difficulty level:\n";
	cout << "1. Easy (0-10)(5 lives)\n";
	cout << "2. Medium (0-50)(3 lives)\n";
	cout << "3. Hard (0-100)(1 live)\n\n";

	short int difficultyLevel;
	cout << "Type a difficulty number: ";
	cin >> difficultyLevel;

	while(difficultyLevel <= 0 || difficultyLevel >= 4) {
		cout << "\rWrong input! Type a difficulty number: ";
		cin >> difficultyLevel;
	}

	// Game start
	gameStart(difficultyLevel);

	return 0;
}