#include "functions.h"
#include <iostream>
#include <fstream>

using namespace std;

int check(int array[], int size, int numberToBeCheck)
{

	for (int i = 0; i < size; i++)
	{
		if (array[i] == numberToBeCheck)			//go through the array to find if there is a match
		{
			cout << "Number of " << numberToBeCheck << " founded at index : " << i << endl;
			return i;								// return the index to the program
		}
	}
													// output no match message
	cout << "There is no match found for number " << numberToBeCheck << "!" << endl;
	return -1;
}

int modify(int array[], int& size, int index, int new_value)
{
	int old_value;
	old_value = array[index];			// assign the number at the index to old_value
	array[index] = new_value;			// assign new_value to the number at the index
	cout << "The old value at index " << index << " is: " << old_value << endl;		//display old and new values to user
	cout << "The new value entered is: " << new_value << endl;
	ofstream rewrite;
	rewrite.open("File after modify a number.txt");			//write modification to the file "File after modify a number.txt"
	cout << "Total numbers: " << size << endl;
	for (int i = 0; i < size; i++)
	{
		if (i % 10 == 0 && i != 0)							//write a newline character after every 10 numbers 
			rewrite << endl << array[i] << " ";
		else
			rewrite << array[i] << " ";
	}
	rewrite.close();
	return old_value;
}




void addnewNumber(int array[], int& size, int newNumber)
{
	int* tempArray;							//a temporary array used to change the size of the original array
	tempArray = new int[size];				//set the temporary array with the old size of the original array
	for (int i = 0; i < size; i++)			// copy all data from original array to temporary array
		tempArray[i] = array[i];
	delete[] array;							//delete original array 
	size = size + 1;						//increase size by 1
	array = new int[size];					//create the original array with new size
	for (int i = 0; i < size - 1; i++)		// copy back all data from the temporary array to the original array
		array[i] = tempArray[i];
	array[size - 1] = newNumber;			// the last number of the new array will be assigned with the new number
	delete[] tempArray;						// delete temporary array
	ofstream rewrite;
	rewrite.open("File after add a new number.txt");    // write the changes to "File after add a new number.txt"

	for (int i = 0; i < size; i++)
	{

		if (i % 10 == 0 && i != 0)
			rewrite << endl << array[i] << " ";
		else
			rewrite << array[i] << " ";
	}
	rewrite.close();
	cout << newNumber << " is added to the array" << endl;;
	cout << "Total numbers: " << size << endl;			// total number after add 1 number
}

void removeNumber(int array[], int& size, int index)
{
	
	int* tempArray2;					//a temporary array used to change the size of the original array
	tempArray2 = new int[size];			//set the temporary array with the old size of the original array		
	for (int i = 0; i < size; i++)		// copy all data from original array to temporary array
		tempArray2[i] = array[i];

	delete[] array;						// delete original array
	size = size - 1;					// decrease size by 1
	array = new int[size];				//create the original array with new size

	for (int i = 0; i < index; i++)		// copy back the data from the temporary array except the number at the index
	{
		array[i] = tempArray2[i];
	}
	for (int i = index; i < size; i++)
		array[i] = tempArray2[i + 1];

	delete[] tempArray2;				// delete temporary array
	ofstream rewrite;
	rewrite.open("File after remove a number.txt");			// write the changes to "File after remove a number.txt"

	for (int i = 0; i < size; i++)
	{

		if (i % 10 == 0 && i != 0)
			rewrite << endl << array[i] << " ";
		else
			rewrite << array[i] << " ";
	}
	rewrite.close();
	cout << "number at index " << index << " is removed!" << endl;
	cout << "Total numbers: " << size << endl;				//total number after remove 1 number
}

