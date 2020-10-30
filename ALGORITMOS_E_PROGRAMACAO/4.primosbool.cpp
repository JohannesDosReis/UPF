#include <iostream>
using namespace std;

int main()
{
	for (int n = 2; n < 1000; n++)
	{
		bool primo = true;
		for (int i = 2; i < n; i++)
		{
			if (n%i == 0)
			{
				primo = false;
				break;
			}
		}
		if (primo) {
			cout << n << " ";
		}
	}
	return 0;
}