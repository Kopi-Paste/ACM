/* H */

#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main()
{
	int size;
	cin >> size;
	vector<int> tempratures = vector<int>();
	int newInt;
	for (int i = 0; i < size; i++)
	{
		cin >> newInt;
		tempratures.push_back(newInt);
	}
	sort(tempratures.begin(), tempratures.end());
 
	auto begin = tempratures.begin();
	auto end = tempratures.end() - 1;
	vector<int> sorted = vector<int>();
	bool fromBegin = true;
	while (begin != end)
	{
		if (fromBegin)
			sorted.push_back(*begin++);
		else
			sorted.push_back(*end--);
		fromBegin = !fromBegin;
	}
	sorted.push_back(*begin);
	for (int i = size - 1; i >= 0; i--)
	{
		cout << sorted[i] << ' ';
	}
	return 0;
}