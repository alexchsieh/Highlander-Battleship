#include <string>
#include <iostream>

#ifndef UTILS_H
#define UTILS_H

using namespace std;

// input validation requires two ints, to indicate the allowed range for input
// the function will prompt a user to enter an int until an appropriate one is entered
int getInt(int min, int max)
{
	string retString;
	getline(cin, retString);
	bool isGoodInput=false;
	int nIter=0;
	char tempChar;
	bool isNeg=false;
	int retInt=0;

	while (!isGoodInput)
	{
		isGoodInput = true;
		// prompt fot input again if input was bad
		if (nIter>0)
		{
			cout<<"Bad input! Please enter an integer between "<<min;
			cout<<" and "<<max<<"."<<endl;
			getline(cin, retString);
		}
		if (retString.length()>0) 
		{
			// process the string, char by char, to see if it's a numeric
			for (int i=0; i<retString.length(); i++)
			{
				tempChar = static_cast<char>(retString[i]);
				// if the first character is a negatve, note it, and continue
				if (i==0 & tempChar=='-')
				{
					isNeg=true;
				}
				// if char is numeric, update the integer to be returned
				else 
				{
					if (tempChar>=48 && tempChar<=57)
					{
						retInt = retInt*10+(static_cast<int>(tempChar)-
																48);
					}
					else // if any non-ints encountered, break loop
					{
						isGoodInput = false;
						break;
					}
				}
			}
		}
		// zero length inputs are bad inputs
		else
		{
			isGoodInput=false;
		}

		// if negative, mutiply by -1
		if (isGoodInput && isNeg)
		{
			retInt = (-1)*retInt;
		}
		// check that int is between limits
		if (isGoodInput && (retInt<min || retInt>max))
		{
			isGoodInput = false;
		}

		// if input was bad, reset trackers and start over again
		if (!isGoodInput) 
		{
			retInt=0;
			isNeg=false;
		}
			
		nIter++;
	}

	return retInt;
};

string getString(int maxLen)
{
	string retString;
	getline(cin, retString);
	while (retString.length()>maxLen)
	{
		cout<<"String too long! Please enter a string with <=";
		cout<<maxLen<<" characters:"<<endl;
		getline(cin, retString);
	}

	return retString;
};


#endif