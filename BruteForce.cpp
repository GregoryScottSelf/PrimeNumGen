//Greg Self 
//CSI 335- Brute Force Algorithm for Prime Numbers
//The purpose of this algorithm is to show that is is inefficient to use a brute force algorithm when finding primes.
#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;

int main()
{
	ofstream output("C:\\Users\\User\\Desktop\\File1.txt");
	if (!output)
	{
		cout << "Error.Output file not found." << endl;
		exit(1);
	}
	clock_t start_Time, end_Time;
	//CountNumberOfPrimes begins at 2 because the prime numbers 1 and 2 are precalculated, no need to perform modulo math
	int CountNumberOfPrimes = 2;
	int input = 0;
	cout << "Enter in the amount of prime numbers to be displayed:";
	cin >> input;
	cout << endl;
	/*input validation:

	must be an integer greater than zero
	cannot be a char

	*/

	while (input <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(3000, '\n');
		cout << "Invalid input" << endl;
		cout << "Enter in the amount of prime numbers to be displayed: " << endl << endl;
		cin >> input;
	}
	//breakerpoint is used as a flag to determine if a number is prime or not
	bool breakerpoint = 0;
	cout << "Printing to outputfile, this will take some time for larger inputs ..." << endl << endl;

	/*input check here:

	If the input is equal to 1 or 2 no caluclations are required
	-Immediatley end the program there is no reason to go into the outter for loop if the user enters in 1 or 2
	-Any input that is greater than 1 or 2, modulo math will be performed below

	*/
	start_Time = clock();
	if (input == 1)
	{
		output << "1" << endl;
		cout << "Calculations complete, open output file to view the list of prime numbers" << endl;
		end_Time = clock();
		//displaying calculations for time here since program will be terminated after this if statement 

		float difference((float)end_Time - (float)start_Time);
		// Number of clocks
		cout << "Total number of CPU clocks : " << difference << endl;
		//calculating runtime in seconds 
		float seconds = difference / CLOCKS_PER_SEC;
		cout << "time in seconds : " << seconds << endl;
		//program is exited 
		exit(1);
	}
	if (input == 2)
	{
		output << "1" << endl;
		output << "2" << endl;
		cout << "Calculations complete, open output file to view the list of prime numbers" << endl;
		end_Time = clock();
		//displaying calculations for time here since program will be terminated after this if statement 

		float difference((float)end_Time - (float)start_Time);
		// Number of clocks
		cout << "Total number of CPU clocks : " << difference << endl;
		//calculating runtime in seconds 
		float seconds = difference / CLOCKS_PER_SEC;
		cout << "time in seconds : " << seconds << endl;
		//program is exited 
		exit(1);
	}
	/*
	If the input in larger than 1 or 2 then 1 and 2 are automatically printed to the screen
	-Then modulo math is performed

	FOR EXAMPLE
	If 3 is the input then the program will list (Modulo math begins at 3):
	1
	2
	3

	*/
	else
	{
		output << "1" << endl;
		output << "2" << endl;
	}
	/*the outer for loop is used to iterate to each prime number
	-The loop begins at 3 because the prime numbers 1 and 2 will be automatcially printed to the screen
	CountNumberOfPrimes will be equal to 2, so the third prime number will be the starting point

	*/
	for (int i = 3; i>0; ++i)
	{


		/*inner for loop carries out the heavy lifting of the program
		-This section of code determines if a number is prime or not by performing modulo math
		-To reduce runtime once the halfway point is reached for calculating if a number is prime
		the algorithm stops computation and beings calculating the next prime
		FOR EXAMPLE 10%2, there is no point to do any calculations past 5 since it is half of 10
		*/
		for (int j = 2; j <=i/2; ++j)
		{
			
			if (i%j == 0) {
				//flagged to true since number is not prime
				breakerpoint = 1;
				break;
			}
		}
		//if the breakerpoint is not changed to true then the number is prime
		if (breakerpoint == 0)
		{
			output << i << endl;
			CountNumberOfPrimes++;
		}
		//reset back to false for next itteration of the outer for loop 
		breakerpoint = 0;
		//once the last prime number is printed based on user input, the program is done and breaks out of outer for loop 
		if (CountNumberOfPrimes == input)
		{
			break;
		}
	}
	cout << "Calculations complete, open output file to view the list of prime numbers" << endl;
	end_Time = clock();
	float difference((float)end_Time - (float)start_Time);
	// Number of clocks
	cout << "Total number of CPU clocks : " << difference << endl;
	//calculating runtime in seconds 
	float seconds = difference / CLOCKS_PER_SEC;
	cout << "time in seconds : " << seconds << endl;
	return 0;
}
