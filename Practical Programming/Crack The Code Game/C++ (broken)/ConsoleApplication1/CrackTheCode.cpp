// Crack The Code Game.cpp : Defines the entry point for the console application.

/* TODO:
- Finish the program
- Work out bugs
*/
#include "stdafx.h"

using namespace std;

int len(int a[]) {
	return sizeof(a) / sizeof(int);
}

void gameGeneration();

bool checkArray(vector<int> a, vector<int> b) {
	/* The lazy method
	if((a[0]==b[0]) && (a[1]==b[1]) && a[2]==b[2]){
	return true;
	}*/
	// A Solution that I'm quite proud of
	bool valueFound = false;
	bool arrayThing[sizeof(a)/sizeof(int)];

	for (int i = 0; i < a.size() && !valueFound;) {
		if (a[i] == b[i]) {
			arrayThing[i] = true;
		}
		else {
			arrayThing[i] = false;
		}
	}

	for (int x = 0; x < (sizeof(arrayThing)/sizeof(bool));) {
		if (arrayThing == 0) {
			return false;
		}
	}
	return true;
}

int randomGenerator(int amount) {
	srand((unsigned)time(0));
	return (rand() % amount);
}

int * keyNumberGeneration(int keyLength) {
	static int key[3];
	vector <int> keyThing;

	while (true) {
		if (keyThing.size() == keyLength) {
			break;
		}
		else {
			vector<int> randomNumberVector;
			randomNumberVector.push_back(randomGenerator(9));

			if (checkArray(randomNumberVector, keyThing)) {
				keyThing.push_back(randomNumberVector[1]);
			}
		}
	}

	key[0] = keyThing[0];
	key[1] = keyThing[1];
	key[2] = keyThing[2];

	return key;
}

int * invalidNumbers(int *key,int length) {
	vector <int> invalidNumbers;
	static int invalidNumbersArray[3];
	vector <int> tempKey;
	tempKey[0] = key[0];
	tempKey[1] = key[1];
	tempKey[1] = key[2];

	while (true) {
		if (invalidNumbers.size() == 3) {
			break;
		}
		else {
			vector <int> randomNumberVector;
			randomNumberVector.push_back(randomGenerator(9));

			if (!(checkArray(randomNumberVector, tempKey)) && !(checkArray(randomNumberVector, invalidNumbers))) {
				invalidNumbers.push_back(randomNumberVector[0]);
			}
		}
	}

	invalidNumbersArray[0] = invalidNumbers[0];
	invalidNumbersArray[1] = invalidNumbers[1];
	invalidNumbersArray[2] = invalidNumbers[2];

	return invalidNumbersArray;
}

void a() {
	cout << "1";
	int *key = keyNumberGeneration(3);
	
	cout << endl << key[0] << key[1] << key[2];


	int *invalidNumber = invalidNumbers(key, 3);
	
	vector <int> attempt;

	//cout << checkArray(attempt, key) << endl;
	//cout << attempt << endl;

	//while (!checkArray(attempt, key)) {
		//system("cls");

		cout << "[" << key[0] << "]" << "[" << invalidNumber[2] << "]" << "[" << invalidNumber[0] << "]" << "One number is correct and well placed\n";
		cout << "[" << invalidNumber[1] << "]" << "[" << invalidNumber[0] << "]" << "[" << invalidNumber[2] << "]" << "Nothing is correct\n";
		cout << "[" << invalidNumber[0] << "]" << "[" << key[0] << "]" << "[" << invalidNumber[2] << "]" << "One number is correct but wrong placed\n";
		cout << "[" << key[1] << "]" << "[" << key[2] << "]" << "[" << invalidNumber[2] << "]" << "Two numbers are correct but wrong placed\n";
		cout << "[" << invalidNumber[1] << "]" << "[" << invalidNumber[2] << "]" << "[" << key[0] << "]" << "One number is correct but wrong placed\n\n";

		int attemptRaw;
		cin >> attemptRaw;


	//}
}

void gameGeneration() {
	cout << "1";
	a();
}

int main()
{
	cout << "1";
	a();
	gameGeneration();
	return 0;
}

