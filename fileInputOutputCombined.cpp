#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//Create a number variable to receive user input to write to a file
	int number = 0;

	//Create an output file stream object named out_a
	ofstream out_a;
	
	//Open a file named numbers.dat
	out_a.open("numbers.dat");

	//Error check and close program
	if (out_a.fail())
	{
		cout << "Unable to open file numbers.dat";
		exit(1);
	}
	//Create a condition for a loop
	char cont = 'y';

	//Ask user if they wish to continue
	while (cont == 'y')
	{
		//Ask user to write a number to save to the file
		cout << "Type a number to save to the file: " << endl;
		//Read the user input
		cin >> number;
		// Write the number to the dat file with a space delimiting the entry
		out_a << number << " ";
		//Ask to type another number
		cout << "Type another number? (y/n)";
		//Assign the answer as the condition for the loop
		cin >> cont;
	}

	//Close the file output stream object
	out_a.close();
	
	//Create input file stream object
	ifstream in_a;

	//Designate the file to open 
	in_a.open("numbers.dat");

	//Error checking exits the program
	if (in_a.fail())
	{
		cout << "Something went wrong. \nMaybe you should check your numbers.dat file's existence...";
		exit(1);
	}
	//Create 5 variables to store the first 5 integers numbers that are read from numbers.dat
	int one, two, three, four, five;

	//Read the first 5 integer numbers from numbers.dat
	in_a >> one >> two >> three >> four >> five;

	//Write to the console the first 5 numbers
	cout << "Our previous numbers are " << one << " " << two << " " << three << " " << four << " " << five << endl;

	//Pause the system so it doesn't close for people opening in Visual Studio
	system("pause");

	//Close the input file stream object
	in_a.close();

	return 0;
}