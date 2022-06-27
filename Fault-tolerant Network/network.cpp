#include <bits/stdc++.h>

using namespace std;



int absDiff(const int x, const int y)
{
	int abs = x - y;
	// cout << "Diff between: " << x << " " << y << " = " << abs << endl;
	return abs > 0 ? abs : -abs;
}

int findClosest(vector<int> & sorted, const int elem)
{
	auto found = lower_bound(sorted.begin(), sorted.end(), elem);
	if (found == sorted.end())
		return absDiff(elem, *(found - 1));
	if (found == sorted.begin())
		return absDiff(elem, *found);
	// cout << "Found : " << *found << endl;
	int optionOne = absDiff(elem, *found);
	int optionTwo = absDiff(elem, *(found - 1));
	return optionOne < optionTwo ? optionOne : optionTwo;
}


// double straight
int firstCase(vector<int> & a, vector<int> & b, vector<int> & sortedA, vector<int> & sortedB, int size)
{
	int sum = 0;
	sum += absDiff(a[0], b[0]);
	sum += absDiff(a[size - 1], b[size - 1]);
	return sum;
}

// big cross
int secondCase(vector<int> & a, vector<int> & b, vector<int> & sortedA, vector<int> & sortedB, int size)
{
	int sum = 0;
	sum += absDiff(a[0], b[size - 1]);
	sum += absDiff(a[size - 1], b[0]);
	return sum;
}

// left straight with right cross
int thirdCase(vector<int> & a, vector<int> & b, vector<int> & sortedA, vector<int> & sortedB, int size)
{
	int sum = 0;
	sum += absDiff(a[0], b[0]);
	sum += findClosest(sortedB, a[size - 1]);
	sum += findClosest(sortedA, b[size - 1]);
	return sum;
}

// right straight with left cross
int fourthCase(vector<int> & a, vector<int> & b, vector<int> & sortedA, vector<int> & sortedB, int size)
{
	int sum = 0;
	sum += absDiff(a[size - 1], b[size - 1]);
	sum += findClosest(sortedB, a[0]);
	sum += findClosest(sortedA, b[0]);
	return sum;
}

// two crosses
int fifthCase(vector<int> & a, vector<int> & b, vector<int> & sortedA, vector<int> & sortedB, int size)
{
	int sum = 0;
	sum += findClosest(sortedB, a[0]);
	sum += findClosest(sortedA, b[0]);
	sum += findClosest(sortedB, a[size - 1]);
	sum += findClosest(sortedA, b[size - 1]);

	return sum;
}

// double slashed left-right
int sixthCase(vector<int> & a, vector<int> & b, vector<int> & sortedA, vector<int> & sortedB, int size)
{
	int sum = 0;
	sum += absDiff(a[0], b[size - 1]);
	sum += findClosest(sortedB, a[size - 1]);
	sum += findClosest(sortedA, b[0]);
	
	return sum;
}

// double slashed right-left
int seventhCase(vector<int> & a, vector<int> & b, vector<int> & sortedA, vector<int> & sortedB, int size)
{
	int sum = 0;
	sum += absDiff(a[size - 1], b[0]);
	sum += findClosest(sortedB, a[0]);
	sum += findClosest(sortedA, b[size - 1]);

	return sum;
}

void solve()
{
	vector<int> a, b;

	int size;

	cin >> size;

	int input;

	for (int i = 0; i < size; i++)
	{
		cin >> input;
		a.push_back(input);
	}

	for (int i = 0; i < size; i++)
	{
		cin >> input;
		b.push_back(input);
	}

	vector<int> sortedA, sortedB;

	sortedA = a;
	sortedB = b;

	sort(sortedA.begin(), sortedA.end());
	sort(sortedB.begin(), sortedB.end());

	vector<int> finalResults;

	int min = INT_MAX;

	finalResults.push_back(firstCase(a, b, sortedA, sortedB, size));
	finalResults.push_back(secondCase(a, b, sortedA, sortedB, size));
	finalResults.push_back(thirdCase(a, b, sortedA, sortedB, size));
	finalResults.push_back(fourthCase(a, b, sortedA, sortedB, size));
	finalResults.push_back(fifthCase(a, b, sortedA, sortedB, size));
	finalResults.push_back(sixthCase(a, b, sortedA, sortedB, size));
	finalResults.push_back(seventhCase(a, b, sortedA, sortedB, size));

	for (auto x : finalResults)
	{
		if (x < min && x >= 0)
			min = x;
	}
	
	cout << min << endl;
}

int main()
{
	int tests;

	cin >> tests;

	for (int i = 0; i < tests; i++)
	{
		solve();
	}
	return 0;
}