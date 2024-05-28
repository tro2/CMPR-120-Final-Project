#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_ALLOWED = 20;

void displayBalance(double balance);
void addCredits(double& balance);
void playGame(double& balance, int& missedGuesses, int& correctGuesses, int& guesses);
void displayStats(string& fullName, double balance, int missedGuesses, int correctGuesses, int guesses);
void saveStats(string& fullName, double balance, int missedGuesses, int correctGuesses, int guesses);
void exit();
void ensureNameExists(string& fullName);
string generateFileName(const string& fullName);

int main()
{
	double balance = 0;
	int guesses = 0;
	int correctGuesses = 0;
	int missedGuesses = 0;
	string fullName;

	srand(time(0));

	int menuChoice;
	bool running = true;
	while (running)
	{
		cout << "***Hello World Trifecta***" << endl << endl;
		cout << "***Menu***" << endl << endl;

		cout << "Please select one of the following" << endl << endl;
		cout << "1: Display available credit" << endl;
		cout << "2: Add credits to my account" << endl;
		cout << "3: Play the guessing game" << endl;
		cout << "4: Display my statistics" << endl;
		cout << "5: Save my statistics" << endl;
		cout << "6: To exit" << endl << endl;
		cin >> menuChoice;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << endl << endl;

		switch (menuChoice)
		{
		case 1:
			displayBalance(balance);
			break;
		case 2:
			addCredits(balance);
			break;
		case 3:
			playGame(balance, missedGuesses, correctGuesses, guesses);
			break;
		case 4:
			displayStats(fullName, balance, missedGuesses, correctGuesses, guesses);
			break;
		case 5:
			saveStats(fullName, balance, missedGuesses, correctGuesses, guesses);
			break;
		case 6:
			exit();
			running = false;
			break;
		default:
			cout << "Please enter valid value" << endl;
		}
	}
	return 0;
}

void displayBalance(double balance) // case 1
{
	cout << "You entered 1: Display available credit" << endl;
	cout << "Your available balance is: $" << balance << endl << endl;
}

void addCredits(double& balance) // case 2
{
	cout << "You entered 2: Add credits to my account" << endl;
	cout << "=> Please enter the amount you would like to add: ";
	int amount;
	do {
		cin >> amount;
		cout << endl << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (amount < 0.0f || amount + balance >= MAX_ALLOWED)
			cout << "Invalid value, Please try again" << endl;
	} while (amount < 0.0f || amount + balance >= MAX_ALLOWED);

	balance += amount;
	cout << "You balance is now: $" << balance << endl << endl << endl;
}

void playGame(double& balance, int& missedGuesses, int& correctGuesses, int& guesses) // case 3
{
	if (balance < 1)
	{
		cout << "You do not have enough credits to play, please add some and try again!" << endl << endl << endl;
		return;
	}

	cout << "You entered 3: Play the Guessing Game" << endl;

	int ranNum;
	int guessNum;
	do
	{
		cout << "Guess a number from 1 to 10! " << endl;
		cin >> guessNum;
		cout << endl << endl;

		ranNum = (rand() % 10) + 1;

		if (guessNum == ranNum)
		{
			cout << "Congratulations, you guessed correctly! You won $2!" << endl << endl << endl;
			balance += 2;
			correctGuesses++;
		}
		else
		{
			cout << "Sorry! the correct number was: " << ranNum << endl << endl << endl;
			balance -= 1;
			missedGuesses++;
		}
		guesses++;

		cout << "If you would like to continue playing please enter 1" << endl;
		cout << "If not enter any other number" << endl;
		cin >> guessNum;
	} while (guessNum == 1 && balance >= 1);
}

void displayStats(string& fullName, double balance, int missedGuesses, int correctGuesses, int guesses) // case 4
{
	cout << "You entered 4: Display my statistics" << endl;

	ensureNameExists(fullName);

	cout << "Date and time: " << __DATE__ << "  " << __TIME__ << endl;
	cout << "Players Name: " << fullName << endl;
	cout << "Available credit: " << balance << endl;
	cout << "Correct Guesses: " << correctGuesses << endl;
	cout << "Missed Guesses: " << missedGuesses << endl;
	cout << "Money won: " << correctGuesses * 2 << endl;
	cout << "Money lost: " << missedGuesses * 1 << endl << endl << endl;
}

void saveStats(string& fullName, double balance, int missedGuesses, int correctGuesses, int guesses) // case 5
{
	cout << "You entered 5: Save my statistics" << endl;

	ensureNameExists(fullName);

	ofstream outFile;
	outFile.open(generateFileName(fullName));
	outFile << "Date and Time: " << __DATE__ << " " << __TIME__ << endl;
	outFile << "Players Name: " << fullName << endl;
	outFile << "Available credits: " << balance << endl;
	outFile << "Games Played: " << guesses << endl;
	outFile << "Correct Guesses: " << correctGuesses << endl;
	outFile << "Missed Guesses: " << missedGuesses << endl;
	outFile << "Money won: " << correctGuesses * 2 << endl;
	outFile << "Money lost: " << missedGuesses * (-1) << endl << endl;

	outFile.close();

	cout << "Your statistics have been saved." << endl << endl;
}

void exit() // case 6
{
	cout << "You entered 6: Thank you for using The Hello World Trifecta software. Good bye!";
}

void ensureNameExists(string& fullName)
{
	if (fullName.empty())
	{
		cout << "Please enter your full name: ";
		getline(cin, fullName);
	}
}

string generateFileName(const string& fullName)
{
	string fileName;
	int startIndex = 0;
	int count = 0;
	for (int i = 0; fullName[i] != '\0'; i++)
	{
		if (fullName[i] == ' ')
		{
			count = i - startIndex;
			fileName.append(fullName.substr(startIndex, count));
			// assuming single spaces
			startIndex = i + 1;
		}
	}
	fileName.append(fullName.substr(startIndex, fullName.length() - startIndex) + ".txt");
	return fileName;
}