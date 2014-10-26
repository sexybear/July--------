#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char long_ch[] = "ABCDEFGHLMNOPQRS";
	char short_ch[] = "DEFGHXLMNOPQ";

	int i;
	bool store[58];
	memset(store,false,58);

	for(i = 0;i < sizeof(short_ch)-1;i++)
	{
		store[short_ch[1]-65] = true;
	}

	for(i = 0;i < sizeof(long_ch)-1;i++)
	{
		if(store[long_ch[i]-65] != false)
		{
			store[long_ch[i]-65] = false;
		}
	}

	for(i = 0;i < 58;i++)
	{
		if(store[i] != false)
		{
			cout << "short_ch is not in long_ch" << endl;
			break;
		}

		if(i == 57)
		{
			cout << "short_ch is in long_ch" << endl;
		}
	}

	return 0;
}