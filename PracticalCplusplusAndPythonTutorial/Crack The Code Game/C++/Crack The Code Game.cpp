// Crack The Code Game.cpp : Defines the entry point for the console application.

/* TODO:
	- Finish checkArray()
	- Finish the program
*/
#include "stdafx.h"

using namespace std;

int randomGenerator(int amount){
	srand((unsigned)time(0));
	return (rand() % amount);
}

int len(int a[]){
	return sizeof(a)/sizeof(int);
}

int keyNumberGeneration(keyLength){
	int key[keyLength];

	while(true){
		if (len(key) == keyLength){
			break;
		}
		else{
			randomNumber = randomGenerator(9);

			if(searchArray(randomNumber, key)){
				key.push_back(randomNumber);
			}
		}
	}
	return key;
}

int invalidNumbers(int key[], int length){
	int invalidNumbers[length];

	while(true){
		if (len(invalidNumbers) == 3){
			break;
		}
		else{
			randomNumber = randomGenerator(9);

			if(!(searchArray(randomNumber, key)) && !(searchArray(randomNumber, invalidNumbers))){
				invalidNumbers.push_back(randomNumber);
			}
		}
	}
	return invalidNumbers;
}

int checkArray(int a[], int b[]){
	// TODO
}

void gameGeneration(){
	
	void a(){
		int key[3] = {keyNumberGeneration(3)};
		int invalidNumbers[3] = invalidNumbers(key, 3);
		int attempt[3];

		while(checkArray(attempt, key)){

		}
	}
}

int main()
{
    return 0;
}

