/*
Logic behind the code is from http://www.sosmath.com/matrix/coding/coding.html

This code describes how to encrypt a messages using the knowledge of invertible matrices. It is a really simple implementation of the example in the above URL.

If we have a message B, we can put it in a matrix form, and encrypt it using AB. Then we can send this encrypted message AB to anyone. To decrypt/get message B back, we use the following property:

A^-1 (AB) = B

Super simple!
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <sstream>

using namespace std;

//we matrix-multiply any message matrix B with this to get the encrypted message.
int A[3][3] =
{
	{ -1, 5, -1,}, // row 0
	{ -2, 11, 7,}, // row 1
	{ 1, -5, 2,} // row 2
};


//we use this to decrypt and get the original message matrix B
int Ainv[3][3] =
{
	{ 57, -5, 46,}, // row 0
	{ 11, -1, 9,}, // row 1
	{ -1, 0, -1	,} // row 2
};


//function to convert string of characters to matrix
string encryptMessage(string message)
{
	while (message.size() % 3 != 0)
	{
		message += " ";
	}

	int B[3][message.size()/3];

	for (int i = 0; i < 3; i ++)
	{
		int val = i;
		for (int j = 0; j < message.size()/3; j++)
		{
			if (val < message.size())
			{
				B[i][j] = message[val];
			}
			else
			{
				B[i][j] = (int)' ';
			}
			val += 3;
		}
	}

	int newMatrix[3][numColumns]
	for(i = 0; i < 3 ; i++)
    {
        for(j = 0; j < numColumns; j++)
        {
            newMatrix[i][j] = 0;
            for(int k = 0; k < 3; k++)
            {
                newMatrix[i][j]= newMatrix[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    string encryptedMessage = "";

    for (int j = 0; j < numColumns; j++)
    {
    	for (int i = 0; i < 3; i++)
    	{
    	 encryptedMessage = encryptedMessage + ",";
    	}
    }

    return encryptedMessage;
}

//function to decrypt an encrypted message where the encrypted message looks like this: "1,2,3,4,5" (int separated by comma delimiters)
string decryptMessage(string encryptedMessage)
{
	stringstream ss(encryptedMessage);
	vector<int> result;

	while(ss.good())
	{
	    string substr;
	    getline(ss, substr, ',');
	    result.push_back((int)substr);
	}

	int numColumns = result.size()/3;

	int encryptedMatrix[3][numColumns];

	int resultIndex = 0;

	for (int j = 0; j < numColumns; i++)
	{
		for (int i = 0; i < 3; i++)
		{
			encryptedMatrix[i][j] = result[resultIndex];
			resultIndex++;
		}
	}

	int decryptedMatrix[3][numColumns];
	for(i = 0; i < 3 ; i++)
    {
        for(j = 0; j < numColumns; j++)
        {
            decryptedMatrix[i][j] = 0;
            for(int k = 0; k < 3; k++)
            {
                decryptedMatrix[i][j]= decryptedMatrix[i][j] + Ainv[i][k] * encryptedMatrix[k][j];
            }
        }
    }

    int outputIndex = 0;
    string output = "";

	for (int j = 0; j < numColumns; i++)
	{
		for (int i = 0; i < 3; i++)
		{
			char charToOutput = decryptedMatrix[i][j];
			output += charToOutput;
		}
	}

	return output;
}

int main()
{
	string input;

	while (true)
	{
		cout << "Press E to encrypt a message, D to decrypt a message, or Q to quit. Case sensitive." << endl;
		cin >> input;

		if (input == "Q")
		{
			cout << "Program exited." << endl;
			break;
		}
		else if (input == "E")
		{
			cout << "Type your message to encrypt." << endl;
			cin >> input;
			cout << encryptMessage(input) << endl;

		}
		else if (input == "D")
		{
			cout << "Type your encrypted message." << endl;
			cin >> input;
			cout << decryptMessage(input) << endl;
		}
		else
		{
			cout << "Command not found." << endl;
		}
	}

	return 0;
}