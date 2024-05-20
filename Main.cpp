#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::string;

const double MAX_ALLOWED = 20;

void displayMainMenu();

int main()
{
	double balance = 0.0;
	double amount = 0.0;
	int correctGuesses = 0;
	int missedGuesses = 0;
	string fullName;

	int choice;
	time_t now;
	bool running = true;
	while (running)
	{
		displayMainMenu();

		cin >> choice;
		switch (choice) {
		case 1:
			cout << "You entered 1: Display available credit" << endl;
			cout << "Your available balance is: $" << balance << endl;
			break;
		case 2:
			cout << "You entered 2: Add credits to my account" << endl;
			cout << "=> Please enter the amount you would like to add: ";
			cin >> amount;
			while (amount > MAX_ALLOWED)
			{
				// TODO flush the input buffer
				cout << "=> Error: Maximum allowable credit is $20.00." << endl;
				cout << "=> Please enter a different amount and try again." << endl;
				cin >> amount;
			}
			balance += amount;
			break;
		case 3:
			cout << "You entered 3: Play the guessing game" << endl;
			cout << "$1 to play" << endl;
			// TODO make the game
			break;
		case 4:
			cout << "You entered 4: Display my statisitcs" << endl;

			// TODO, only run this once, if name has not been entered
			// CHECK WITH PROFESSOR, CLARIFY PROGRAM REQS
			cout << "Please enter your full name: ";
			cin.ignore();
			getline(cin, fullName);

			// Output to console
			// TODO abstract this into function that takes a basic_ostream arg
			// Get the current date and time
			now = time(nullptr);
			cout << "Data and time: " << ctime(&now);
			cout << "Player Name: " << fullName << endl;
			cout << "Available credit: " << amount << endl;
			cout << "Correct Guesses: " << correctGuesses << endl;
			cout << "Missed Guesses: " << missedGuesses << endl;
			// TODO format money outputs to two decimal places using
			cout << "Money you won: " << correctGuesses * 2 << endl;
			cout << "Money you lost: " << missedGuesses * 1 << endl;
			break;
		case 5:
			cout << "You entered 5: Save my statistics" << endl;
			// TODO use abstracted function from above
			break;
		case 6:
			cout << "You entered 6: Thank you for using The Hello World Trifecta software. Good bye!";
			running = false;
			break;
		}
	}
	return 0;
}

void displayMainMenu()
{
	cout << "***Hello World Trifecta***" << endl << endl;
	cout << "***Menu***" << endl << endl;

	cout << "Please select one of the following" << endl << endl;
	cout << "1: Display avaialbe credit" << endl;
	cout << "2: Add credits to my account" << endl;
	cout << "3: Play the guessing game" << endl;
	cout << "4: Display my statisitcs" << endl;
	cout << "5: Save my statistics" << endl;
	cout << "6: To exit" << endl;
}
