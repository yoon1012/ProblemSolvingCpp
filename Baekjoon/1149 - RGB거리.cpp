#include <iostream>
#include <algorithm>

using namespace std;

int a[1000][3];
int d[1000][3];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i][0];
		cin >> a[i][1];
		cin >> a[i][2];
	}

	d[0][0] = a[0][0];
	d[0][1] = a[0][1];
	d[0][2] = a[0][2];

	for (int i = 1; i < n; i++)
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0];
		d[i][1] = min(d[i - 1][2], d[i - 1][0]) + a[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i][2];
	}

	int min;

	if (d[n - 1][0] < d[n - 1][1])
	{
		min = d[n - 1][0];
	}
	else
	{
		min = d[n - 1][1];
	}

	if (d[n - 1][2] < min)
	{
		min = d[n - 1][2];
	}

	cout << min << "\n";
	
	return 0;
}
