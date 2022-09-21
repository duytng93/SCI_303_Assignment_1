#include <iostream>
#include <fstream>
#include "functions.h"


using namespace std;

int main()
{
	int numberToBeCheck, numberToBeCheck2;		// variable for user input in question 1
	int index, newNumber;						// variables for user input in question 2
	int newNumber2;								// variable for user input in question 3
	int index2;									// variable for user input in question 4
	ifstream inputFile;
	int* array;
	int size = 0;								// size is initialized to 0 in order to perform couting

	inputFile.open("File.txt");
	if (!inputFile)								// test if file is available
	{
		cout << "file not found!" << endl;
	}

	int read;									// a varible for the counting process

	while (!inputFile.eof())					//read file to determine the size of array
	{
		inputFile >> read;
		size++;
	}
	array = new int[size];						// creat array with the appropirate size
	inputFile.close();

	inputFile.open("File.txt");					// read the file to input integers to the array
	while (!inputFile.eof())
	{
		for (int i = 0; i < size; i++)
		{
			inputFile >> array[i];

		}
	}
	inputFile.close();

	cout << endl;
	cout << "Enter a number to be checked: ";
	cin >> numberToBeCheck;
	check(array, size, numberToBeCheck);				// 1) Check if a certain integer exists in the array
	cout << endl;
	cout << "====================" << endl << endl;		// if the number is present 
														// return the index where the number is present.
	cout << "Enter a number to be checked: ";
	cin >> numberToBeCheck2;
	check(array, size, numberToBeCheck2);				// if the number is not found, display a message
	cout << endl;
	cout << "====================" << endl << endl;


	cout << "Enter the index of the number to be modified: ";
	cin >> index;
	cout << "Enter the new number: ";
	cin >> newNumber;
	modify(array, size, index, newNumber);				// 2) A function that can modify the value of an integer when called
	cout << endl;										// with the index of the integer in the array
	cout << "====================" << endl << endl;		// and return the new value and old value back to the user.

	cout << "Enter a number to add to the array: ";
	cin >> newNumber2;
	addnewNumber(array, size, newNumber2);				// 3) A function that adds a new integer 
	cout << endl;										//    to the end of the array.
	cout << "====================" << endl << endl;

	cout << "Enter the number index to be removed: ";
	cin >> index2;
	removeNumber(array, size, index2);					// 4)	A function which intakes an index of an array
														// and remove the integer corresponding to that index.
	cout << endl;
	cout << "Program ends!" << endl;
	delete[] array;
	system("pause");
	return 0;
}

