//Project: CIS022_S2017_Assignment8b
//Module: CIS022_S2017_Assignment8b\ Morgan\ Shorter-McFarlane.cpp
//Developer: Morgan Shorter-McFarlane
//Date: March 22, 2017
//Purpose: Read data from a CSV file. Use that data to calculate a pay value. Write the input data along with the pay value to the output file.
//
//
//
//
//


#include "stdafx.h"	//include standard c++ libs
#include <iostream>	//include standard I/O library
#include <string>	//include the magic string library
#include <fstream>	//include the filestream librarby

using namespace std;	//use the standard namespace



int _tmain(int argc, _TCHAR* argv[])	//main program entry point
{
	ifstream inFile;	// declare a input filestream var
	string szSourcePath =	"./CIS022_Assignment8b.csv";		// path of input file, change to your file location, if necessary
	ofstream outFile;	//declare output filestream var
	string szDestPath = "./out.csv";					// path of output file, change to your file location, if necessary

	string szLastName;	//declare string variables to hold the input data
	string szFirstName;
	string szAddress;
	string szCity;
	string szState;
	string szZip;
	string szWage;
	string szHours;
	string szPay;

	inFile.open(szSourcePath);	//open the input file
	outFile.open(szDestPath);	//open the output file

	float pay = 0.0;	//declare float variables so I can do math with the input
	float wage = 0.0;
	float hours = 0.0;

	char c = ',';  //to save time typing the output string
// this code reads the first line of the input file only
// insert loop to read entire file here

	while (!inFile.eof())	//keep looping over these instructions until the end of the input file is reached
	{
		getline( inFile, szLastName, ','); //split a line of the input into several variables
		getline( inFile, szFirstName, ',');
		getline( inFile, szAddress, ',');
		getline( inFile, szCity, ',');
		getline( inFile, szState, ',');
		getline( inFile, szZip, ',');
		getline( inFile, szWage, ',');
		getline( inFile, szHours, '\n');

// calculate pay here

		wage = ::atof(szWage.c_str());	//convert the wages and hours from string to float type
		hours = ::atof(szHours.c_str());
		pay = wage * hours; 		//calculate pay

// insert write to output file here

		outFile << szLastName+c+szFirstName+c+szAddress+c+szAddress+c+szCity+c+szState+c+szZip+c+szWage+c+szHours+c+pay+"\n";	//write a line of output to the output file by combining the split-up input from above and adding the calculated pay data
	
	}


	inFile.close();	//close the input file
	outFile.close();//close the output file


	system("Pause");//pause execution and wait for a user keypress
	return 0;	//end the program
}

