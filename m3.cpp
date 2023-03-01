/*
* Filename: m3.cpp
* Project: Major 3
* By: Jongeon Lee
* Date: Mar , 2023
* Description: Write a program that calculates hotel bills for a meeting.
*/

#include <string>
#include <iostream>
#include <sstream>

#define ERROR -1

using namespace std;

int dayToIndex(string inputString);
double calculateCostOfRoom(const double arrRoomRate[], int ckeckIn, int checkOut);

int main()
{
	const double arrPrice[6] = {127.50, 128.25, 130.50, 150, 150, 162.50}; //daily room cost(sunday ~ saturday)
	const int kPeopleNum = 4;
	double roomRatePersonal = 0.00;
	double arrRatePersonal[kPeopleNum] = { 0 };
	double totalPrice = 0;
	int strCheckInIndex = 0;
	int strCheckOutIndex = 0;
	string name;
	string checkIn;
	string checkOut;

	for (int i=0; i<kPeopleNum; i++)
	{
		cout << "Name: ";
		getline(cin, name);
		
		if (name != "")
		{
			cout << "When are they checking in: ";
			getline(cin, checkIn);
			strCheckInIndex = dayToIndex(checkIn);

			if (strCheckInIndex != ERROR)
			{
				cout << "When are they checking out: ";
				getline(cin, checkOut);
				strCheckOutIndex = dayToIndex(checkOut);

				if (strCheckOutIndex != ERROR)
				{
					if (strCheckInIndex < strCheckOutIndex)
					{
						if (strCheckInIndex <= 5 && strCheckOutIndex >= 5)
						{
							roomRatePersonal = calculateCostOfRoom(arrPrice, strCheckInIndex, strCheckOutIndex);
							cout << "The room cost for " << name << " is " << roomRatePersonal << "." << endl << endl;
						}
						else
						{
							cout << "Error: this person is missing the meeting. Skipping this person." << endl << endl;
						}
					}
					else
					{
						cout << "Error: invalid length of stay. Skipping this person." << endl << endl;
					}
				}
				else
				{
					cout << "Error: invalid check-out day. Skipping this person." << endl << endl;
				}
			}
			else
			{
				cout << "Error: invalid check-in day. Skipping this person." << endl << endl;
			}
		}
		else
		{
			cout << "Error: name missing. Skipping this person." << endl << endl;
		}
		arrRatePersonal[i] = roomRatePersonal;
		roomRatePersonal = 0;
	}

	for (int j = 0; j < kPeopleNum; j++)
	{
		totalPrice += arrRatePersonal[j];
	}

	cout << "The total room cost for everyone is " << totalPrice << "." << endl;

	return 0;
}

/*
* Function: dayToIndex()
* Description: This function is for changing input string to number.
* Parameters: string inputString - This is input string from user. it could be day.
* Returns: ERROR - This function returns to the global variable ERROR -1.
*/
int dayToIndex(string inputString)
{
	if (inputString == "sun")
	{
		return 1;
	}
	else if (inputString == "mon")
	{
		return 2;
	}
	else if (inputString == "tue")
	{
		return 3;
	}
	else if (inputString == "wed")
	{
		return 4;
	}
	else if (inputString == "thu")
	{
		return 5;
	}
	else if (inputString == "fri")
	{
		return 6;
	}
	else if (inputString == "sat")
	{
		return 7;
	}
	else
	{
		return ERROR;
	}
}

/*
* Function: calculateCostOfRoom()
* Description: This function calculates the room cost.
* Parameters:
	- arrCheckIn - This is room cost array.
	- ckeckIn - This variable is day index of check-in.
	- checkOut - This variable is day index of check-out.
* Returns: result - This is room cost calculated by the room cost array.
*/
double calculateCostOfRoom(const double arrRoomRate[], int ckeckIn, int checkOut)
{
	double result = 0;
	
	for (int i = ckeckIn - 1; i <= checkOut - 2; i++)
	{
		result += arrRoomRate[i];
	}
	return result;
}