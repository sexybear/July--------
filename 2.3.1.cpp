#include <iostream>
#include <string>
#include "BigInt.h"

using namespace std;

int primenumber[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,67,71,73,79,83,89,97,101};

int main()
{
	string strOne = "ABCDEFGHLMOPQRS";
	string strTwo = "EFGJKL";

	CBigInt product = 1;

	for(itn i = 0; i<strOne.length();i++)
	{
		int index = strOne[1] - 'A';
		product = product * primenumber[index];
	}

	for(int j = 0;j < strTwo.length();j++)
	{
		int index = strTwo[j] - 'A';

		if(product % primernumber[index] != 0)
		{
			break;
		}
	}

	if(strTwo.length() == j)
	{
		cout << "true" << endl;
	}

	else
	{
		cout << "false" << endl;
	}

	return 0;
}