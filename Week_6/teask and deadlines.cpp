#include <bits/stdc++.h>
#define vii vector<pair<int, int>>
using namespace std;

int main()
{
	int n, a, b;
	cin >> n;
	vii arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		arr[i] = make_pair(a, b);
	}
	sort(arr.begin(), arr.end());
	long long int total = 0, curr = 0;
	for (auto ele : arr)
	{
		curr += ele.first;
		total += ele.second - curr;
	}
	cout << total;
	return 0;
}