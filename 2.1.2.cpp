#include <iostream>
#include <string>

using namespace std;

int partition(string &str, int lo, int hi)
{
	int key = str[hi];
	int i = lo -1;

	for(int j = lo;j<hi;j++)
	{
		if(str[j] <= key)
		{
			i++;
			swap(str[i],str[j]);
		}
	}
	swap(str[i+1],str[hi]);
	return i+1;

}

void quicksort(string &str,int lo,int hi)
{
	if(lo < hi)
	{
		int k = partition(str,lo,hi);
		quicksort(str,lo,k-1);
		quicksort(str,k+1,hi);
	}
}

void compare(string str1,string str2)
{
	int posOne = 0;
	int posTwo = 0;
	while(posTwo < str2.length() && posOne < str1.length())
	{
		while(str1[posOne] < str2[posTwo] && posOne < str1.length() - 1)
		{
			posOne++;
		}
		if(str1[posOne] != str2[posTwo])
		{
			break;
			posTwo++;
		}
		if(posTwo == str2.length())
		{
			cout << "True" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}
}

int main()
{
	string str1 = "ABCDEFGHIJKLMNOPQRS";
	string str2 = "DCGDSRQPOM";

	quicksort(str1,0,str1.length() -1);
	quicksort(str2,0,str2.length() -1);

	compare(str1,str2);

	return 0;
}