// Banking Program.cpp : Defines the entry point for the console application.
// CSV file syntax: bankAccountNum, bankAccountName, bankAccountBalance 

#include "stdafx.h"

using namespace std;

int main()
{
	ifstream file("file.csv");

	std::vector <int> bankAccountNum;
	std::vector <string> bankAccountName;
	std::vector <float> bankAccountBalance;

	string value;
	int lengthOfVector = 0;
	int i;
	int searchedIndex;

	while (file.good()) {

		// For account number
		getline(file, value, ',');
		bankAccountNum.push_back(stoi(value));

		// For account name
		getline(file, value, ',');
		bankAccountName.push_back(value);

		// For account balance
		getline(file, value, ',');
		bankAccountBalance.push_back(stoi(value));

		lengthOfVector += 1;
	}
	int userChoice = 0;

	cout << "Enter Bank Account Number" << endl;
	cin >> userChoice;

	bool valueFound = false;

	for (i = -1; (i < lengthOfVector) && !valueFound;) {
		if (userChoice == bankAccountNum[i]) {
			searchedIndex = i;
			valueFound = true;
		}
		++i;
	}

	if (valueFound) {
		cout << "Bank Account Number Found!" << endl;
		system("PAUSE");
	}
	else {
		cout << "Number is not in the database!" << endl;
		cout << "Would you like to make an account? y/n" << endl;
		string userStringChoice;
		cin >> userStringChoice;
		if (userStringChoice == "y") {
			// make an account
		}
	}

    return 0;
}