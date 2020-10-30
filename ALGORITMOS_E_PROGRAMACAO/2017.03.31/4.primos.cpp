#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k, primo;
	for (n = 1; n <= 1000; n++)
	{
		primo = 0;
		for (k = 2; k <= n; k++)
			if ((n%k) == 0)
				primo++;
		if (primo == 1)
		{
			cout << n << " ";
		}
	}
	cout << endl;
	return 0;
}
