#include <iostream>
#include <string>

using namespace std;

void CounterSort(string str,string &help_str)
{
	int help[26] = {0};

	for(int i = 0;i< str.length();i++)
	{
		int index = str[i] - 'A';
		help[index]++;
	}

	for(int j = 1;j<26;j++)
	{
		help[j] += help[j-1];
	}

	for(int k = str.length()-1;k>=0;k--)
	{
		int index = str[k] - 'A';
		int pos = help[index] -1;
		help_str[pos] = str[k];
		help[index]--;
	}
}

void Compare(string long_str,string short_str)
{
	int pos_long = 0;
	int pos_short = 0;
	while(pos_short < short_str.length() && pos_long < long_str.length())
	{
		while(long_str[pos_long] < short_str[pos_short] && pos_long < long_str.length()-1)
		{
			pos_long++;
		}
		while(short_str[pos_short] == short_str[pos_short+1])
		{
			pos_short++;
		}
		if(long_str[pos_long] != short_str[pos_short])
		{
			break;
		}
		pos_long++;
		pos_short++;
	}
	if(pos_short == short_str.length())
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
}

int main()
{
	string strOne = "ABCDAK";
	string strTwo = "A";
	string long_str = strOne;
	string short_str = strTwo;


	CounterSort(strOne,long_str);
	CounterSort(strTwo,short_str);

	Compare(long_str,short_str);
	return 0;
}