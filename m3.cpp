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

using namespace std;

int kError = 0;
int dayToIndex(string inputString); //sun=1, mon=2, tue=3, wed=4, thu=5, fri=6, sat=7
double calculateCostOfRoom(const double arrRoomRate[], int arrCheckIn, int arrCheckOut);

int main()
{
	const double arrPrice[6] = {127.50, 128.25, 130.50, 150, 150, 162.50};
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
		std::getline(cin, name);
		
		if (name != "")
		{
			cout << "When are they checking in: ";
			std::getline(cin, checkIn);
			strCheckInIndex = dayToIndex(checkIn);

			if (kError != -1)
			{
				cout << "When are they checking out: ";
				std::getline(cin, checkOut);
				strCheckOutIndex = dayToIndex(checkOut);
				if (kError != -1)
				{
					if (strCheckInIndex < strCheckOutIndex)
					{
						if ((strCheckInIndex-strCheckOutIndex == 0) || (strCheckOutIndex < 5))
						{
							cout << "Error: invalid length of stay. Skipping this person." << endl << endl;

						}
						else if (strCheckInIndex >= 6)
						{
							cout << "Error: this person is missing the meeting. Skipping this person." << endl << endl;
						}
						else
						{
							roomRatePersonal = calculateCostOfRoom(arrPrice, strCheckInIndex, strCheckOutIndex);
							cout << "The room cost for " << name << " is " << roomRatePersonal << "." << endl << endl;
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
					kError = 0;
				}
			}
			else
			{
				cout << "Error: invalid check-in day. Skipping this person." << endl << endl;
				kError = 0;
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
* Description: 
* Parameters: 
* Returns: 
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
		return kError = -1;
	}
}

/*
* Function: calculateCostOfRoom()
* Description: 
* Parameters:
* Returns:
*/
double calculateCostOfRoom(const double arrRoomRate[], int arrCheckIn, int arrCheckOut)
{
	double result = 0;
	
	for (int i = arrCheckIn - 1; i <= arrCheckOut - 2; i++)
	{
		result += arrRoomRate[i];
	}
	return result;
}
