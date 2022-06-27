/* C */

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
 
using namespace std;
 
int main()
{
	int n, k, d, s;
	cin >> n >> k;
	cin >> d >> s;
	double result = (double)((n * d) - (k * s)) / (double)(n - k);
	if (result >= 0 && result <= 100)
	{
		cout << setprecision(9);
		cout << result  << endl;
	}
	else
	{
		cout << "impossible" << endl;
	}
	return 0;
}