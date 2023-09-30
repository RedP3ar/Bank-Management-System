// Bank Management System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <conio.h>
#include <string>
#include <stdio.h>

using namespace std;

bool del = true;
int input;
int accId;
int regCode;
string regName;
string deleteData;

string fileName = "Accounts.txt";

bool check4(int code) //4 digit code checker
{
	return code > 999 && code <= 9999;
}

fstream accList;

void fileRead() { //read data from file
	accList.open(fileName, ios::in);
	if (!accList.is_open())
	{
		system("color 4");
		cerr << "Error opening file \"" << fileName << "\" when trying to read" << endl;
		cerr << "Maybe the file doesn't exist?" << endl;
	}
	else
	{
		cout << "************************" << endl;
		cout << "     Accounts list" << endl;
		cout << "************************" << endl;
		cout << endl << endl;

		while (!accList.eof())
		{
			string accounts;

			getline(accList, accounts);

			cout << accounts << endl;
		}

		cout << "************************" << endl;
	}

	accList.close();
}

void fileWrite(string name, int code) //write data to file
{
	accList.open(fileName, ios::app);

	accList << "ID: " << accId << endl;
	accList << "Name: " << name << endl;
	accList << "Code: " << code << endl;
	accList << endl;

	accList.close();

	system("color a");

	cout << "**********************************" << endl;
	cout << endl;

	cout << "Account Created Successfully!!" << endl;
	cout << endl;
	cout << "Account ID: " << accId << endl;
	cout << "Account Name: " << name << endl;
	cout << "Account Code: " << code << endl;

	cout << endl;
	cout << "**********************************" << endl;
	cout << endl;
	accId++;

	accList.close();

	system("pause");
	system("color 7");
	system("cls");
}

void accReg() {
	cout << "Input Account Name: ";
	cin.ignore(1);
	getline(cin, regName);

	cout << "Input Account Code (4 digit): ";
	cin >> regCode;

	if (!check4(regCode))
	{
		system("cls");
		system("color 4");
		cout << "!!Error!! Inputted code doesn't meet the requirements" << endl;
		regName = "0";
		regCode = 0;
		system("pause");
		system("color 7");
		system("cls");
		accReg();
	}
	else
	{
		cout << endl;
		system("cls");
		fileWrite(regName, regCode);
	}
}

void settings()
{
	del = 1;

	cout << "**************************" << endl;
	cout << "      Settings Panel" << endl;
	cout << "**************************" << endl;
	cout << endl;
	cout << "1. Delete Accounts Database" << endl;
	cout << "0. Go back to Main Menu" << endl;
	cout << endl;
	cout << "Chose a option: ";
	cin >> input;

	switch (input)
	{
	case 0:
		system("cls");
		break;

	case 1:
		system("cls");
		while (del)
		{
			cout << "Are you sure that you want to delete" << endl
				<< "all the data included in the Accounts Database? Y/N" << endl;
			cin >> deleteData;

			if (deleteData == "y" || deleteData == "Y")
			{
				system("cls");
				if (remove("Accounts.txt") == 0)
				{
					system("color a");
					cout << "Database cleared successfully" << endl;
					accId = 0;
					del = 0;
					system("pause");
				}
				else
				{
					system("color 4");
					cout << "!!Error while deleting database!!" << endl;
					cout << "Maybe the file doesn't exist" << endl;
					del = 0;
					system("pause");
				}
			}

			else if (deleteData == "n" || deleteData == "N")
			{
				del = 0;
			}
		}
		system("color 7");
		system("cls");
		settings();
		break;

	default:
		system("cls");
		break;
	}
}

void mainMenu() {
	cout << "*********************" << endl;
	cout << endl;
	cout << "1 - Register" << endl;
	cout << "2 - Login" << endl;
	cout << "3 - List Accounts" << endl;
	cout << "4 - Settings" << endl;
	cout << "0 - Exit" << endl;
	cout << endl;
	cout << "*********************" << endl;

	cout << endl;
	cout << "Chose a option: ";
	cin >> input;

	switch (input)
	{
	case 0:
		break;

	case 1:
		system("cls");
		accReg();
		mainMenu();
		break;

	case 2:
		system("cls");
		system("color 4");
		cout << "****************************" << endl;
		cout << "    !!NOT IMPLEMENTED!!" << endl;
		cout << "****************************" << endl;
		system("pause");
		system("color 7");
		system("cls");
		mainMenu();
		break;

	case 3:
		system("cls");
		fileRead();
		system("pause");
		system("color 7");
		system("cls");
		mainMenu();
		break;

	case 4:
		system("cls");
		settings();
		mainMenu();
		break;

	default:
		system("cls");
		mainMenu();
		break;
	}
}

int main()
{
	mainMenu();
	return 0;
}